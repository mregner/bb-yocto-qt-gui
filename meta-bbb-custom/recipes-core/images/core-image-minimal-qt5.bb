require recipes-core/images/core-image-minimal.bb

inherit populate_sdk_qt5

IMAGE_INSTALL += " qtbase i2c-tools kernel-module-bno055 imu-helper"
CONFLICT_DISTRO_FEATURES = "x11 wayland"
