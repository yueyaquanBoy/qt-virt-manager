qt-virt-manager
=================
![Main widget]( https://github.com/F1ash/qt-virt-manager/blob/master/Pictures/snapshot12.png )
[![Join the chat at https://gitter.im/F1ash/qt-virt-manager](https://badges.gitter.im/F1ash/qt-virt-manager.svg)](https://gitter.im/F1ash/qt-virt-manager?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

A GUI application for managing virtual machines.

Known issues:

    1. If failures occur in connections that are using ssh,
       you must ensure that in the system installed ssh
       and an application like ssh-askpass for your DE,
       also the environment variable SSH_ASKPASS was set.
       For example: SSH_ASKPASS=/usr/bin/ksshaskpass
       You can do it in $HOME/.bash_profile file at least.

    2. Adding devices implemented partially.

    3. In Spice client viewer:

        * the paste from client system clipboard

          to guests clipboard is not work;

        * the Smartcard manager is not implemented yet.

Building parameters:

    BUILD_QT_VERSION
        if not defined or equal 4, then will build with Qt4,
        if equal 5, then with Qt5

    WITH_LIBCACARD
        if defined and above zero, then libcacard.h required
        and will used SpiceSmartcard Channel for smartcards

    USE_SPICE_AUDIO
        if not defined or above zero, then will used
        Spice[Playback/Record] Channels for audio

Build requires:

    * with Qt4              (optional, BUILD_QT_VERSION=4)
    libQtCore.so
    libQtGui.so
    libQtMultimedia.so
    libQtSvg.so
    libQtXml.so
    libQtNetwork.so
    libqtermwidget4.so

    * with Qt5              (required, BUILD_QT_VERSION=5)
    libQt5Core.so
    libQt5Gui.so
    libQt5Multimedia.so
    libQt5Svg.so
    libQt5Widgets.so
    libQt5Xml.so
    libQt5Network.so
    libqtermwidget5.so

    libcacard.so            (optional, WITH_LIBCACARD)

    libgio-2.0.so
    libglib-2.0.so
    libgmodule-2.0.so
    libgobject-2.0.so
    libgthread-2.0.so
    libspice-client-glib-2.0.so
    libvncclient.so
    libvirt.so

