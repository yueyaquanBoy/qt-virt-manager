#ifndef DOMAIN_CONTROL_MENU_H
#define DOMAIN_CONTROL_MENU_H

#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QStringList>
#include <QDebug>

class DomainControlMenu : public QMenu
{
    Q_OBJECT
public:
    explicit DomainControlMenu(
            QWidget     *parent = nullptr,
            QStringList  params = QStringList(),
            bool         state  = false);

signals:
    void            execMethod(const QStringList&);

private:
    bool            autoReloadState;
    QAction        *start = nullptr;
    QAction        *pause = nullptr;
    QAction        *destroy = nullptr;
    QAction        *edit = nullptr;
    QAction        *reset = nullptr;
    QAction        *reboot = nullptr;
    QAction        *shutdown = nullptr;
    QAction        *save = nullptr;
    QAction        *undefine = nullptr;
    QAction        *autoStart = nullptr;
    QAction        *getXMLDesc = nullptr;
    QAction        *RunningData = nullptr;
    QAction        *InactiveData = nullptr;
    QMenu          *xmlDescParams = nullptr;
    QAction        *migrate = nullptr;
    QAction        *display = nullptr;
    QAction        *addToMonitor = nullptr;
    QAction        *reload = nullptr;
    QAction        *createSnapshot = nullptr;
    QAction        *moreSnapshot_Actions = nullptr;
    QStringList     parameters;

private slots:
    void            emitExecMethod(QAction*);

};

#endif // DOMAIN_CONTROL_MENU_H
