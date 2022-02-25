#include <stdio.h>
#include <iio.h>

struct channels {
    struct iio_channel *accel_x;
    struct iio_channel *accel_y;
    struct iio_channel *accel_z;
    struct iio_channel *yaw;
    struct iio_channel *pitch;
    struct iio_channel *roll;
};

void init_channels(struct iio_device *dev, struct channels *ch_handles) {
    ch_handles->accel_x = iio_device_find_channel(dev, "accel_x", false);
    ch_handles->accel_y = iio_device_find_channel(dev, "accel_y", false);
    ch_handles->accel_z = iio_device_find_channel(dev, "accel_z", false);
    ch_handles->roll = iio_device_find_channel(dev, "angl_x", false);
    ch_handles->pitch = iio_device_find_channel(dev, "angl_y", false);
    ch_handles->yaw = iio_device_find_channel(dev, "angl_z", false);
}

double get_ch_scaled_value(struct iio_channel *channel) {
    double raw, scale;
    iio_channel_attr_read_double(channel, "raw", &raw);
    iio_channel_attr_read_double(channel, "scale", &scale);
    return raw * scale;
}

int main() {
    struct channels ch_handles;
    struct iio_context *local_ctx;
    local_ctx = iio_create_local_context();
    struct iio_device *dev = iio_context_find_device(local_ctx, "BNO055 IMU");
    printf("Device %s ID: %s\n", iio_device_get_name(dev), iio_device_get_id(dev));
    init_channels(dev, &ch_handles);

    printf("X Acceleration: %.2f\n", get_ch_scaled_value(ch_handles.accel_x));
    printf("Y Acceleration: %.2f\n", get_ch_scaled_value(ch_handles.accel_y));
    printf("Z Acceleration: %.2f\n", get_ch_scaled_value(ch_handles.accel_z));
    printf("Yaw: %.2f\n", get_ch_scaled_value(ch_handles.yaw));
    printf("Pitch: %.2f\n", get_ch_scaled_value(ch_handles.pitch));
    printf("Roll: %.2f\n", get_ch_scaled_value(ch_handles.roll));

    return 0;
}