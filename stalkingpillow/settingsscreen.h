#ifndef SETTINGSSCREEN_H
#define SETTINGSSCREEN_H

#include <QWidget>
#include <QSettings>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>

class SettingsScreen : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsScreen(QWidget *parent = 0);
    ~SettingsScreen();
private:
    QVBoxLayout* layout;
    QLabel* titleLabel;
    QLabel* facebookLabel;
    QLabel* userLabel;
    QLabel* passLabel;
    QLabel* notificationLabel;
    QLabel* messageLabel;
    QCheckBox* notificationCheck;
    QLineEdit* userField;
    QLineEdit* passField;
    QLineEdit* messageField;
    QPushButton* saveButton;

    //add timer interval
signals:

private slots:
    void saveData();
};

#endif // SETTINGSSCREEN_H
