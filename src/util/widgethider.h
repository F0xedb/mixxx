#ifndef MIXXX_UTIL_WIDGETHIDER_H
#define MIXXX_UTIL_WIDGETHIDER_H

#include <QWidget>
#include <QEvent>

// TODO: The following is needed so that the encoder settings don't change size
// and position when hiding some of the options.
// With QT 5.2 onwards, there is an easier solution:
// http://doc.qt.io/qt-5/qsizepolicy.html#setRetainSizeWhenHidden
// Source based on:
// http://stackoverflow.com/questions/10794532/how-to-make-a-qt-widget-invisible-without-changing-the-position-of-the-other-qt/34663079#34663079
class WidgetHider : public QObject {
    Q_OBJECT
  public:
    WidgetHider(QObject* parent = 0);
    bool eventFilter(QObject*, QEvent* ev) override;
    void retainSizeFor(QWidget* widget);
    void hideWidget(QWidget* w);
    void showWidget(QWidget* w);
};

#endif // MIXXX_UTIL_WIDGETHIDER_H
