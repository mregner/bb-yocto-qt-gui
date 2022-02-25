
#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/iio/iio.h>
#include "bno055.h"
#include "bno055_channels.h"

#define DEFAULT_MODE BNO055_OPR_MODE_NDOF

// IIO

struct bno055_user_data {
	struct i2c_client *cl;
};

static int bno055_read_accel(struct i2c_client *cl, const struct iio_chan_spec *chan, int *val, int *val2, long info) {
	if (info == IIO_CHAN_INFO_SCALE) {
		*val = 1;
		*val2 = 100;
		return IIO_VAL_FRACTIONAL;
	}
	if (info != IIO_CHAN_INFO_RAW) {
		return -EINVAL;
	}
	switch (chan->channel2) {
		case IIO_MOD_X:
			*val = (int16_t)i2c_smbus_read_word_data(cl, BNO055_LINEAR_ACCEL_DATA_X_LSB_ADDR);
			break;
		case IIO_MOD_Y:
			*val = (int16_t)i2c_smbus_read_word_data(cl, BNO055_LINEAR_ACCEL_DATA_Y_LSB_ADDR);
			break;
		case IIO_MOD_Z:
			*val = (int16_t)i2c_smbus_read_word_data(cl, BNO055_LINEAR_ACCEL_DATA_Z_LSB_ADDR);
			break;
		default:
			return -EINVAL;
	}
	return IIO_VAL_INT;
}

static int bno055_read_euler_angle(struct i2c_client *cl, const struct iio_chan_spec *chan, int *val, int *val2, long info) {
	if (info == IIO_CHAN_INFO_SCALE) {
		*val = 1;
		*val2 = 16;
		return IIO_VAL_FRACTIONAL;
	}
	if (info != IIO_CHAN_INFO_RAW) {
		return -EINVAL;
	}
	switch (chan->channel2) {
		case IIO_MOD_X:
			*val = (int16_t)i2c_smbus_read_word_data(cl, BNO055_EULER_R_LSB_ADDR);
			break;
		case IIO_MOD_Y:
			*val = (int16_t)i2c_smbus_read_word_data(cl, BNO055_EULER_P_LSB_ADDR);
			break;
		case IIO_MOD_Z:
			*val = (int16_t)i2c_smbus_read_word_data(cl, BNO055_EULER_H_LSB_ADDR);
			break;
		default:
			return -EINVAL;
	}
	return IIO_VAL_INT;
}

static int bno055_read_raw(struct iio_dev *indio_dev, const struct iio_chan_spec *chan, int *val, int *val2, long info) {
	struct bno055_user_data *data = iio_priv(indio_dev);
	switch (chan->type) {
		case  IIO_ACCEL:
			return bno055_read_accel(data->cl, chan, val, val2, info);
		case IIO_ANGL:
			return bno055_read_euler_angle(data->cl, chan, val, val2, info);
		default:
			return -EINVAL;
	}
}

static const struct iio_info bno055_info = {
	.read_raw = bno055_read_raw,
};

// Core Driver

int bno055_write_confirm_byte(struct i2c_client *cl, u8 reg, u8 value) {
	u8 confirm_val;
	if (i2c_smbus_write_byte_data(cl, reg, value) < 0) {
		dev_err(&cl->dev, "BNO055: Failed to write register 0x%x\n", reg);
		return -EIO;
	}
	confirm_val = i2c_smbus_read_byte_data(cl, reg);
	if (confirm_val != value) {
		dev_err(&cl->dev, "BNO055: Failed register readback 0x%x == 0x%x\n", reg,  value);
		return -EIO;
	}
	return 0;
}

int init_imu(struct i2c_client *cl) {
	int retval;
	retval = bno055_write_confirm_byte(cl, BNO055_OPR_MODE_ADDR, DEFAULT_MODE);
	if (!retval) {
		return retval;
	}

	return 0;
}

static int bno055_probe(struct i2c_client *cl, const struct i2c_device_id *id) {
	struct bno055_user_data *data;
	struct iio_dev *indio_dev;

	dev_info(&cl->dev, "%s called for client addr=%d, name=%s\n", __func__, cl->addr, cl->name);
	init_imu(cl);

	indio_dev = devm_iio_device_alloc(&cl->dev, sizeof(*data));
	if (!indio_dev)  {
		return -ENOMEM;
	}

	data = iio_priv(indio_dev);
	data->cl = cl;

	indio_dev->dev.parent = &cl->dev;
	indio_dev->info = &bno055_info;
	indio_dev->name = "BNO055 IMU";
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = bno055_channels;
	indio_dev->num_channels = ARRAY_SIZE(bno055_channels);

	return iio_device_register(indio_dev);
}

// Driver data and setup

static const struct of_device_id bno055_of_match[] = {
		{ .compatible = "bosch,bno055" },
		{}
};
MODULE_DEVICE_TABLE(of, bno055_of_match);

static const struct i2c_device_id bno055_id[] = {
	{"bno055", 0},
	{}
};
MODULE_DEVICE_TABLE(i2c, bno055_id);

static struct i2c_driver bno055_drv = {
	.driver = {
		.name = "bno055-driver",
		.owner = THIS_MODULE,
		.of_match_table = bno055_of_match
	},
	.probe = bno055_probe,
	.id_table = bno055_id,
};

// Driver entry/exit points
int init_module(void)
{
	return i2c_add_driver(&bno055_drv);
}

void cleanup_module(void)
{
	printk("BNO055 Disconnected\n");
}

MODULE_LICENSE("GPL");
