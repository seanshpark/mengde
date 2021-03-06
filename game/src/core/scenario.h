#ifndef MENGDE_CORE_SCENARIO_H_
#define MENGDE_CORE_SCENARIO_H_

#include "resource_manager.h"
#include "util/common.h"

namespace mengde {
namespace core {

class Assets;
class Stage;

// Scenario data globally used during the entire scenario

class Scenario {
 public:
  Scenario(const string&);
  ~Scenario();
  const ResourceManagers& GetResourceManagers() { return rc_; }
  Assets* GetAssets() { return assets_.get(); }
  Stage* current_stage() { return current_stage_.get(); }

 public:
  const string& id() const { return scenario_id_; }
  bool NextStage();

 private:
  unique_ptr<Stage> NewStage(const string& stage_id);

 private:
  string scenario_id_;
  vector<string> stage_ids_;
  uint32_t stage_no_;
  ResourceManagers rc_;
  unique_ptr<Assets> assets_;
  unique_ptr<Stage> current_stage_;
};

}  // namespace core
}  // namespace mengde

#endif  // MENGDE_CORE_SCENARIO_H_
