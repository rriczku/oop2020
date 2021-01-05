TEMPLATE = subdirs

SUBDIRS += \
    cli \
    gui \
    tests \
    utils

cli.depends = utils
gui.depends = utils
tests.depends = utils

