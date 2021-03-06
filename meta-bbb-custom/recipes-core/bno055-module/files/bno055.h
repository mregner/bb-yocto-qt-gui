#ifndef _BNO055_H
#define _BNO055_H

// Chip IO registers
#define BNO055_CHIP_ID_ADDR (0x00)
#define BNO055_ACCEL_REV_ID_ADDR (0x01)
#define BNO055_MAG_REV_ID_ADDR (0x02)
#define BNO055_GYRO_REV_ID_ADDR (0x03)
#define BNO055_SW_REV_ID_LSB_ADDR (0x04)
#define BNO055_SW_REV_ID_MSB_ADDR (0x05)
#define BNO055_BL_REV_ID_ADDR (0x06)
#define BNO055_PAGE_ID_ADDR (0x07)

// Estimator state read registers
#define BNO055_ACCEL_DATA_X_LSB_ADDR (0x08)
#define BNO055_ACCEL_DATA_X_MSB_ADDR (0x09)
#define BNO055_ACCEL_DATA_Y_LSB_ADDR (0x0A)
#define BNO055_ACCEL_DATA_Y_MSB_ADDR (0x0B)
#define BNO055_ACCEL_DATA_Z_LSB_ADDR (0x0C)
#define BNO055_ACCEL_DATA_Z_MSB_ADDR (0x0D)

#define BNO055_MAG_DATA_X_LSB_ADDR (0x0E)
#define BNO055_MAG_DATA_X_MSB_ADDR (0x0F)
#define BNO055_MAG_DATA_Y_LSB_ADDR (0x10)
#define BNO055_MAG_DATA_Y_MSB_ADDR (0x11)
#define BNO055_MAG_DATA_Z_LSB_ADDR (0x12)
#define BNO055_MAG_DATA_Z_MSB_ADDR (0x13)

#define BNO055_GYRO_DATA_X_LSB_ADDR (0x14)
#define BNO055_GYRO_DATA_X_MSB_ADDR (0x15)
#define BNO055_GYRO_DATA_Y_LSB_ADDR (0x16)
#define BNO055_GYRO_DATA_Y_MSB_ADDR (0x17)
#define BNO055_GYRO_DATA_Z_LSB_ADDR (0x18)
#define BNO055_GYRO_DATA_Z_MSB_ADDR (0x19)

#define BNO055_EULER_H_LSB_ADDR (0x1A)
#define BNO055_EULER_H_MSB_ADDR (0x1B)
#define BNO055_EULER_R_LSB_ADDR (0x1C)
#define BNO055_EULER_R_MSB_ADDR (0x1D)
#define BNO055_EULER_P_LSB_ADDR (0x1E)
#define BNO055_EULER_P_MSB_ADDR (0x1F)

#define BNO055_QUATERNION_DATA_W_LSB_ADDR (0x20)
#define BNO055_QUATERNION_DATA_W_MSB_ADDR (0x21)
#define BNO055_QUATERNION_DATA_X_LSB_ADDR (0x22)
#define BNO055_QUATERNION_DATA_X_MSB_ADDR (0x23)
#define BNO055_QUATERNION_DATA_Y_LSB_ADDR (0x24)
#define BNO055_QUATERNION_DATA_Y_MSB_ADDR (0x25)
#define BNO055_QUATERNION_DATA_Z_LSB_ADDR (0x26)
#define BNO055_QUATERNION_DATA_Z_MSB_ADDR (0x27)

#define BNO055_LINEAR_ACCEL_DATA_X_LSB_ADDR (0x28)
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_ADDR (0x29)
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_ADDR (0x2A)
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_ADDR (0x2B)
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_ADDR (0x2C)
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_ADDR (0x2D)

#define BNO055_GRAVITY_DATA_X_LSB_ADDR (0x2E)
#define BNO055_GRAVITY_DATA_X_MSB_ADDR (0x2F)
#define BNO055_GRAVITY_DATA_Y_LSB_ADDR (0x30)
#define BNO055_GRAVITY_DATA_Y_MSB_ADDR (0x31)
#define BNO055_GRAVITY_DATA_Z_LSB_ADDR (0x32)
#define BNO055_GRAVITY_DATA_Z_MSB_ADDR (0x33)

#define BNO055_TEMP_ADDR (0x34)

// Chip state read registers
#define BNO055_CALIB_STAT_ADDR (0x35)
#define BNO055_SELFTEST_RESULT_ADDR (0x36)
#define BNO055_INTR_STAT_ADDR (0x37)
#define BNO055_SYS_CLK_STAT_ADDR (0x38)
#define BNO055_SYS_STAT_ADDR (0x39)
#define BNO055_SYS_ERR_ADDR (0x3A)

// Basic config read/write registers
#define BNO055_UNIT_SEL_ADDR (0x3B)

// Operating modes
#define BNO055_OPR_MODE_CONFIG (0x0)
#define BNO055_OPR_MODE_ACCEL (0x1)
#define BNO055_OPR_MODE_MAG (0x2)
#define BNO055_OPR_MODE_GYRO (0x3)
#define BNO055_OPR_MODE_ACCMAG (0x4)
#define BNO055_OPR_MODE_ACCGYRO (0x5)
#define BNO055_OPR_MODE_MAGGYRO (0x6)
#define BNO055_OPR_MODE_AMG (0x7)
#define BNO055_OPR_MODE_IMU (0x8)
#define BNO055_OPR_MODE_COMPASS (0x9)
#define BNO055_OPR_MODE_M4G (0xA)
#define BNO055_OPR_MODE_NDOF_FMC_OFF (0xB)
#define BNO055_OPR_MODE_NDOF (0xC)
#define BNO055_OPR_MODE_ADDR (0x3D)

#define BNO055_PWR_MODE_ADDR (0x3E)
#define BNO055_SYS_TRIGGER_ADDR (0x3F)
#define BNO055_TEMP_SOURCE_ADDR (0x40)
#define BNO055_AXIS_MAP_CONFIG_ADDR (0x41)
#define BNO055_AXIS_MAP_SIGN_ADDR (0x42)

// Orientation config read/write registers
#define BNO055_SIC_MATRIX_0_LSB_ADDR (0x43)
#define BNO055_SIC_MATRIX_0_MSB_ADDR (0x44)
#define BNO055_SIC_MATRIX_1_LSB_ADDR (0x45)
#define BNO055_SIC_MATRIX_1_MSB_ADDR (0x46)
#define BNO055_SIC_MATRIX_2_LSB_ADDR (0x47)
#define BNO055_SIC_MATRIX_2_MSB_ADDR (0x48)
#define BNO055_SIC_MATRIX_3_LSB_ADDR (0x49)
#define BNO055_SIC_MATRIX_3_MSB_ADDR (0x4A)
#define BNO055_SIC_MATRIX_4_LSB_ADDR (0x4B)
#define BNO055_SIC_MATRIX_4_MSB_ADDR (0x4C)
#define BNO055_SIC_MATRIX_5_LSB_ADDR (0x4D)
#define BNO055_SIC_MATRIX_5_MSB_ADDR (0x4E)
#define BNO055_SIC_MATRIX_6_LSB_ADDR (0x4F)
#define BNO055_SIC_MATRIX_6_MSB_ADDR (0x50)
#define BNO055_SIC_MATRIX_7_LSB_ADDR (0x51)
#define BNO055_SIC_MATRIX_7_MSB_ADDR (0x52)
#define BNO055_SIC_MATRIX_8_LSB_ADDR (0x53)
#define BNO055_SIC_MATRIX_8_MSB_ADDR (0x54)

// Offset config read/write registers
#define ACCEL_OFFSET_X_LSB_ADDR (0x55)
#define ACCEL_OFFSET_X_MSB_ADDR (0x56)
#define ACCEL_OFFSET_Y_LSB_ADDR (0x57)
#define ACCEL_OFFSET_Y_MSB_ADDR (0x58)
#define ACCEL_OFFSET_Z_LSB_ADDR (0x59)
#define ACCEL_OFFSET_Z_MSB_ADDR (0x5A)

#define MAG_OFFSET_X_LSB_ADDR (0x5B)
#define MAG_OFFSET_X_MSB_ADDR (0x5C)
#define MAG_OFFSET_Y_LSB_ADDR (0x5D)
#define MAG_OFFSET_Y_MSB_ADDR (0x5E)
#define MAG_OFFSET_Z_LSB_ADDR (0x5F)
#define MAG_OFFSET_Z_MSB_ADDR (0x60)

#define GYRO_OFFSET_X_LSB_ADDR (0x61)
#define GYRO_OFFSET_X_MSB_ADDR (0x62)
#define GYRO_OFFSET_Y_LSB_ADDR (0x63)
#define GYRO_OFFSET_Y_MSB_ADDR (0x64)
#define GYRO_OFFSET_Z_LSB_ADDR (0x65)
#define GYRO_OFFSET_Z_MSB_ADDR (0x66)

#define ACCEL_RADIUS_LSB_ADDR (0x67)
#define ACCEL_RADIUS_MSB_ADDR (0x68)

#define MAG_RADIUS_LSB_ADDR (0x69)
#define MAG_RADIUS_MSB_ADDR (0x6A)

#endif
