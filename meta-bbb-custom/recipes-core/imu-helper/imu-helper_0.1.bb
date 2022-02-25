SUMMARY = "Simple helloworld application"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://COPYING;md5=c9f4d86ca567ebf3b70e939afe00bee7"

SRC_URI = "file://imu-helper.c \
           file://COPYING \
           "

S = "${WORKDIR}"
TARGET_CC_ARCH += "${LDFLAGS}"
DEPENDS = "libiio"

do_compile() {
         ${CC} imu-helper.c -liio -o imu-helper
}

do_install() {
         install -d ${D}${bindir}
         install -m 0755 imu-helper ${D}${bindir}
}