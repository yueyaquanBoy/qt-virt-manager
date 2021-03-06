#ifndef REDIR_FILTER_H
#define REDIR_FILTER_H

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class RedirFilter : public QWidget
{
    Q_OBJECT
public:
    explicit RedirFilter(QWidget *parent = nullptr);
    QListWidget     *filter;
    QCheckBox       *filtered;

signals:
    void             dataChanged();

private:
    QLineEdit       *_class, *_product,
                    *_vendor, *_version;
    QPushButton     *add;
    QPushButton     *del;
    QHBoxLayout     *panelLayout;
    QWidget         *panel;
    QVBoxLayout     *baseLayout;
    QWidget         *baseWdg;
    QVBoxLayout     *commonLayout;

public slots:
    bool             isFiltered() const;
    QStringList      getFiltersList() const;
    void             setFiltersList(QString&, bool);

private slots:
    void             addFilter();
    void             delFilter();
};

#endif // REDIR_FILTER_H
