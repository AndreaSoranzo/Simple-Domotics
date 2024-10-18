#ifndef SearchPanel_H
#define SearchPanel_H

#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <vector>

class SearchPanel : public QWidget {
    Q_OBJECT
   private:
    QLineEdit* searchInput;
    QCheckBox* perfectMatch;
    QComboBox* typeFilter;

    QLabel* resultsLabel;

   public:
    explicit SearchPanel(QWidget* parent = 0);
    void ClearInput();

    void UpdateResults(unsigned int number);
   signals:
    void OnSearch(const QString& queryText, const QString& queryFilter, bool match) const;
    void TriggerSearch();
};

#endif  // !SearchPanel_H