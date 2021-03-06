#include "logical_host_cpu.h"
#include <QThread>

LogicalHostCPU::LogicalHostCPU(
        QWidget *parent, uint _cores) :
    QWidget(parent), cores(_cores)
{
    QString _label = QString("Logical host cores: %1").arg(cores);
    logicCPULabel = new QLabel(_label, this);
    icon = new QLabel(this);
    icon->setVisible(false);
    icon->setPixmap(QIcon::fromTheme("dialog-warning")
                    .pixmap(this->fontInfo().pixelSize()));
    info = new QLabel("Overcommitting vCPUs can hurt performance", this);
    info->setVisible(false);
    commonLayout = new QHBoxLayout(this);
    commonLayout->addWidget(logicCPULabel);
    commonLayout->addWidget(icon);
    commonLayout->addWidget(info);
    commonLayout->addStretch(-1);
    setLayout(commonLayout);
}

/* public slots */
void LogicalHostCPU::changeInfoVisibility(int i)
{
    info->setVisible( i>cores );
    icon->setVisible( i>cores );
}
