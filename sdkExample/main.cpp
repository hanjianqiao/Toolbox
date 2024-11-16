#include <QWidget>
#include <hfontawesome/hfontawesome.h>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qSetMessagePattern("[%{type}][%{time}][%{appname}][%{category}] %{message} (%{file}:%{line})");
    qDebug() << "Hello World!";

    QWidget w;
    w.setWindowIcon(h::fontawesome::HFontawesome::icon(fa::fa_regular, fa::fa_cabin));
    w.show();

    return a.exec();
}
