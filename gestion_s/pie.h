#ifndef PIE_H
#define PIE_H

#include <QDialog>

namespace Ui {
class pie;
}

class pie : public QDialog
{
    Q_OBJECT

public:
    explicit pie(QWidget *parent = nullptr);
    ~pie();

private:
    Ui::pie *ui;
};

#endif // PIE_H
