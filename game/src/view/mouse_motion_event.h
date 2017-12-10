#ifndef MOUSE_MOTION_EVENT_H_
#define MOUSE_MOTION_EVENT_H_

#include "util/common.h"

class MouseMotionEvent {
 public:
  enum Type : uint16_t {
    kNone,
    kOver,
    kOut
  };

  MouseMotionEvent(const MouseMotionEvent&, Vec2D);
  MouseMotionEvent(Type, const Vec2D, const Vec2D);
  MouseMotionEvent(Type);
  bool IsMotionOver() const { return motion_ == kOver; }
  bool IsMotionOut() const { return motion_ == kOut; }
  Type GetMotion() const { return motion_; }
  Vec2D GetCoords() const { return coords_; }
  Vec2D GetCoordsRel() const { return coords_rel_; }
  Vec2D GetLastCoords() const { return coords_ - coords_rel_; }

 private:
  Type motion_;
  Vec2D coords_;
  Vec2D coords_rel_;
};

#endif // MOUSE_MOTION_EVENT_H_
