#include "settingsscreen.h"

SettingsScreen::SettingsScreen(QWidget *parent) :
    QWidget(parent)
{
    this->mainLayout = new QVBoxLayout(this);
    this->scroll = new QScrollArea();
    this->mainLayout->addWidget(this->scroll);
    QWidget* contents = new QWidget();
    this->layout = new QVBoxLayout(contents);
    QSettings settings;

    this->titleLabel = new QLabel(this);
    this->titleLabel->setText("<h2><b>Settings</b></h2>");
    this->facebookLabel = new QLabel(this);
    this->facebookLabel->setText("<b>Facebook</b>");
    this->notificationLabel = new QLabel(this);
    this->notificationLabel->setText("<b>Notifications</b>");
    this->userLabel = new QLabel(this);
    this->userLabel->setText("Username");
    this->passLabel = new QLabel(this);
    this->passLabel->setText("Password");
    this->messageLabel = new QLabel(this);
    this->messageLabel->setText("Message");

    this->userField = new QLineEdit(this);
    this->passField = new QLineEdit(this);
    this->passField->setEchoMode(QLineEdit::Password);
    this->messageField = new QLineEdit(this);

    this->notificationCheck = new QCheckBox(this);

    this->saveButton = new QPushButton(this);
    this->saveButton->setText("Save");
    connect(this->saveButton, SIGNAL(released()), this, SLOT(saveData()));

    this->layout->addWidget(this->titleLabel);
    this->layout->addWidget(this->facebookLabel);
    this->layout->addWidget(this->userLabel);
    this->layout->addWidget(this->userField);
    this->layout->addWidget(this->passLabel);
    this->layout->addWidget(this->passField);
    this->layout->addWidget(this->notificationLabel);
    this->layout->addWidget(this->notificationCheck);
    this->layout->addWidget(this->messageLabel);
    this->layout->addWidget(this->messageField);
    this->layout->addWidget(this->saveButton);

    this->layout->setSizeConstraint(QLayout::SetMinimumSize);
    this->scroll->setWidget(contents);

    if (settings.contains("facebook/username")) {
        this->userField->setText(settings.value("facebook/username").toString());
    }
    if (settings.contains("facebook/password")) {
        this->passField->setText(settings.value("facebook/password").toString());
    }
    if (settings.contains("notification/notify")) {
        if (settings.value("notification/notify").toBool()) {
            this->notificationCheck->setChecked(true);
        }
    } else {
        this->notificationCheck->setChecked(true);
        settings.setValue("notification/notify", true);
    }
    if (settings.contains("notification/message")) {
        this->messageField->setText(settings.value("notification/message").toString());
    } else {
        this->messageField->setText("%USER% is online!");
    }
}

void SettingsScreen::saveData() {
    QSettings settings;
    settings.setValue("facebook/username", this->userField->text());
    settings.setValue("facebook/password", this->passField->text());
    settings.setValue("notification/notify", this->notificationCheck->isChecked());
    settings.setValue("notification/message", this->messageField->text());
}

SettingsScreen::~SettingsScreen() {
    delete this->titleLabel;
    delete this->facebookLabel;
    delete this->userLabel;
    delete this->userField;
    delete this->passLabel;
    delete this->passField;
    delete this->notificationLabel;
    delete this->notificationCheck;
    delete this->messageLabel;
    delete this->messageField;
    delete this->saveButton;
}
