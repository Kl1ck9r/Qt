#include "calendar.h"
#include "ui_calendar.h"

Calendar::Calendar(QWidget *parent)
    : QWidget(parent)

{
    createSpinBox();
    createDateTimeEdits();
    createDoubleSpinBox();

    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(spinBoxGroup);
    layout->addWidget(editsGroup);
    layout->addWidget(doubleSpinBoxes);

    setLayout(layout);


    setWindowTitle(tr("Spin Boxes Group"));
}

void Calendar::createSpinBox()
{
    spinBoxGroup=new QGroupBox;

    QLabel *integer=new QLabel(tr("Enter a value  "
                               "%1 and %2: ").arg(-20).arg(20));


    QSpinBox *integerSpin=new QSpinBox;

    integerSpin->setRange(-20,20);
    integerSpin->setSingleStep(1);
    integerSpin->setValue(0);


    QLabel *zoomLabel=new QLabel(tr("Enter a value:  "));
    QSpinBox * zoom=new QSpinBox;
    zoom->setRange(0,1000);
    zoom->setSingleStep(10);
    zoom->setSuffix("%");
    zoom->setSpecialValueText(tr("Automatic"));
    zoom->setValue(100);


    QLabel *priceLabel=new QLabel(tr("Enter a price: "));

    QSpinBox *priceSpin=new QSpinBox;
    priceSpin->setRange(0,999);
    priceSpin->setSingleStep(2);
    priceSpin->setPrefix("$");
    priceSpin->setValue(99);


    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(integer);
    layout->addWidget(integerSpin);
    layout->addWidget(zoomLabel);
    layout->addWidget(zoom);
    layout->addWidget(priceLabel);
    layout->addWidget(priceSpin);

    spinBoxGroup->setLayout(layout);
}

void Calendar::createDateTimeEdits()
{
    editsGroup=new QGroupBox(tr("Date and time spin boxes"));

    QLabel *dateLabel=new QLabel;

    QDateEdit *dateEdit=new QDateEdit(QDate::currentDate());

    dateEdit->setDateRange(QDate(2005,1,1),QDate(2022,1,1));
    dateLabel->setText(tr("Appoitment date: "));


    QLabel *timeLabel=new QLabel;
    QTimeEdit *timeEdit=new QTimeEdit(QTime::currentTime());
    timeEdit->setTimeRange(QTime(9,0,0,0),QTime(22,50,0,0));
    timeLabel->setText(tr("Appoitment time: "));

    meetingLabel=new QLabel("Metting Label");
    meetingEdit=new QDateTimeEdit(QDateTime::currentDateTime());


    QLabel *comboLabel=new QLabel(tr("Format String for the meeting date and time "));

     QComboBox *formatCombo=new QComboBox;
     formatCombo->addItem("yyyy-MM-dd hh:mm:ss (zzz 'ms')");
     formatCombo->addItem("hh:mm:ss MM/dd/yyyy");
     formatCombo->addItem("hh:mm::ss");
     formatCombo->addItem("hh:mm ap");

     connect(formatCombo,SIGNAL(activated(QString)),this,SLOT(setFormatString(QString)));

     setFormatString(formatCombo->currentText());

    QVBoxLayout *_editsLayout=new QVBoxLayout;
    _editsLayout->addWidget(dateLabel);
    _editsLayout->addWidget(dateEdit);
    _editsLayout->addWidget(timeLabel);
    _editsLayout->addWidget(timeEdit);
     _editsLayout->addWidget(meetingLabel);
    _editsLayout->addWidget(meetingEdit);
    _editsLayout->addWidget(comboLabel);
    _editsLayout->addWidget(formatCombo);
    editsGroup->setLayout(_editsLayout);

}

void Calendar::createDoubleSpinBox()
{
    doubleSpinBoxes=new QGroupBox(tr("This doubleSpinBox !"));

    QLabel *doubleLabel=new QLabel(tr("This doubleSpinBox !"));

    doubleSpinBox=new QDoubleSpinBox;
    doubleSpinBox->setRange(1.0,1000.0);
    doubleSpinBox->setSingleStep(6.0);
    doubleSpinBox->setValue(1.0);

    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(doubleLabel);
    layout->addWidget(doubleSpinBox);

    doubleSpinBoxes->setLayout(layout);
}

void Calendar::setFormatString(const QString &formatString)
{
    meetingEdit->setDisplayFormat(formatString);
}



