#ifndef ListPanel_H
#define ListPanel_H

#include <QGridLayout>
#include <QPushButton>
#include <QString>
#include <map>

#include "../../CustomWidgets/Renderers/IRendererStrategy.h"
#include "SearchPanel.h"

class ListPanel : public QWidget {
    Q_OBJECT
   private:
    std::vector<const SensorItem*> displayedItems;
    std::map<unsigned int, const SensorItem*> cache;

    QGridLayout* renderLay;
    SearchPanel* searchPanel;

    IRendererStrategy* renderer;

    const int VERTICAL_SPACING = 10;
    const int HORIZONTAL_SPACING = 20;

    QPushButton* CreateRendererButton(const QString& iconPath, int width, int height, void (ListPanel::*slot)());
    void FetchAllItems();
    void ClearList();
    void UpdateList();
    void DeleteItem(unsigned int idx);

   public:
    explicit ListPanel(QWidget* parent = 0);
    ~ListPanel();
    void UpdateCache(const std::vector<const SensorItem*>& list);
    void ClearAllItems();
    void ClearSearch();
    void Select(const std::vector<unsigned int>& list);

   signals:
    void OnInspect(unsigned int idx);
    void OnDelete(unsigned int idx);
    void OnEdit(unsigned int idx);
    void OnSearch(const QString& queryText, const QString& queryFilter, bool match) const;
    void OnChangeRenderer();

   public slots:
    void SetGrid();
    void SetList();
};

#endif  // !ListPanel_H