// Copyright (c) 2017-2018 The PIVX developers
// Copyright (c) 2019-2020 The OneWorld developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZOneWorldCONTROLDIALOG_H
#define ZOneWorldCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zOWO/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZOneWorldControlDialog;
}

class CZOneWorldControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZOneWorldControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZOneWorldControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZOneWorldControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZOneWorldControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZOneWorldControlDialog(QWidget *parent);
    ~ZOneWorldControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZOneWorldControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZOneWorldControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZOneWorldCONTROLDIALOG_H
