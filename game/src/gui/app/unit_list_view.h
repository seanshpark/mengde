#ifndef MENGDE_GUI_APP_UNIT_LIST_VIEW_H_
#define MENGDE_GUI_APP_UNIT_LIST_VIEW_H_

#include "gui/uifw/composite_view.h"

#include "common.h"

namespace mengde {
namespace core {
class Unit;
}
}  // namespace mengde

namespace mengde {
namespace gui {
namespace app {

class UnitListView : public CompositeView {
 public:
  class UnitDetailView : public CompositeView {
   public:
    UnitDetailView(const Rect&);
    void SetUnit(const core::Unit*);

   private:
    const core::Unit* unit_;
    TextView* tv_name_;
  };

 public:
  UnitListView(const Rect&, const vector<const core::Unit*>&);
  void SetUnit(const core::Unit* unit) { unit_detail_view_->SetUnit(unit); }

 private:
  vector<const core::Unit*> unit_list_;
  UnitDetailView* unit_detail_view_;
};

}  // namespace app
}  // namespace gui
}  // namespace mengde

#endif  // MENGDE_GUI_APP_UNIT_LIST_VIEW_H_
