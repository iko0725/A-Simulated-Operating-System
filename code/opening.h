/* class: Opening
 * --------------
 * Generate a QDialog that preforms booting animation.
*/
#ifndef OPENING_H
#define OPENING_H

#include <QDialog>

namespace Ui {
class Opening;
}

class Opening : public QDialog
{
    Q_OBJECT

public:
    /*
     * Function: Opening(QWidget *parent = nullptr)
     * Usage: QDialog *dlg = new Opening()
     * --------------------------------------------
     * Construct a Opening class QDialog
*/
    explicit Opening(QWidget *parent = nullptr);

    /*
     * Function: ~Opening
     * Usage: Usually implicit
     * --------------------------------------------
     * Dextruct the object and all memories it allocated.
*/
    ~Opening();
    /*
     * Function: paintEvent(QPaintEvent *)
     * Usage: Implicit
     * --------------------------------------------
     * Draw the background for the Opening object.
*/
    void paintEvent(QPaintEvent *);

private:
    Ui::Opening *ui;
};

#endif // OPENING_H
