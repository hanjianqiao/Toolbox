#ifndef HPLAINTEXTEDIT_H
#define HPLAINTEXTEDIT_H

#include <QPlainTextEdit>
#include "../hqt_global.h"

HQT_BEGIN_NAMESPACE

class HPlaintextEditLineNumberArea;

class HQT_EXPORT HPlaintextEdit : public QPlainTextEdit
{
    Q_OBJECT

public:
    enum Shortcut{
        ShiftEnter,
    };

    explicit HPlaintextEdit(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *e) override;

private:
    void init();

Q_SIGNALS:
    void shortcutActivited(Shortcut shortcut);

private Q_SLOTS:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &rect, int dy);

private:
    HPlaintextEditLineNumberArea *m_lineArea;

    friend class HPlaintextEditLineNumberArea;
};

HQT_END_NAMESPACE

#endif // HPLAINTEXTEDIT_H
