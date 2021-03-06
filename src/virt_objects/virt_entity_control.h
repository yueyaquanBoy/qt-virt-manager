#ifndef VIRT_ENTITY_CONTROL_H
#define VIRT_ENTITY_CONTROL_H

#include <QMainWindow>
#include "tree_view.h"
#include <QSettings>
#include <QTime>
#include <QUrl>
#include <QDesktopServices>
#include <QDebug>
#include "virt_objects/virt_entity_config.h"

class VirtEntityControl : public QMainWindow
{
    Q_OBJECT
public:
    explicit VirtEntityControl(QWidget *parent = nullptr);
    virtual ~VirtEntityControl()               = 0;
    QString                  currConnName;
    QSettings                settings;
    TreeView                *entityList;
    virConnectPtr           *ptr_ConnPtr = nullptr;

    virtual void             stopProcessing();
    virtual bool             setCurrentWorkConnect(virConnectPtr*);
    virtual void             setListHeader(QString&);
    virtual void             reloadState();
    virtual void             changeDockVisibility();
    virtual void             entityClicked(const QPoint&);
    virtual void             entityDoubleClicked(const QModelIndex&);
    virtual void             execAction(const QStringList&);
    virtual void             newVirtEntityFromXML(const QStringList&);
    virtual void             doneEntityCreationDialog();

    void                     setUsageInSoftTouched(bool);

signals:
    void                     entityMsg(QString&);
    void                     addNewTask(TASK);
    void                     ptrIsNull();

public slots:
    void                     msgRepeater(QString&);
    virtual void             resultReceiver(Result);
};

#endif // VIRT_ENTITY_CONTROL_H
