#ifndef VIEW_H_
#define VIEW_H_

#include "util/common.h"
#include "gui/foundation/color.h"
#include "gui/foundation/rect.h"
#include "i_view.h"

class Drawer;

class View : public IView {
 public:
  View();
  View(const Rect*);
  View(const Rect&);
  virtual ~View() {}
  const Rect* GetFrame() { return &frame_; }
  Rect GetActualFrame() const;
  Vec2D GetFrameSize() const;
  Vec2D GetActualFrameSize() const;
  Vec2D GetFrameCoords() const;
  Vec2D GetActualFrameCoords() const;
  void SetCoords(Vec2D v) { frame_.SetPos(v); }
  void SetSize(Vec2D v) { frame_.SetSize(v); }
  void Move(Vec2D v) { frame_.Move(v); }
  void SetFrame(const Rect* r) { frame_ = *r; }

  void  bg_color(Color c) { bg_color_ = c; }
  Color bg_color() const  { return bg_color_; }
  void padding(int p)  { padding_ = p; }
  int  padding() const { return padding_; }
  void visible(bool b);
  bool visible() const { return visible_; }

  bool DelegateMouseButtonEvent(const MouseButtonEvent);
  bool DelegateMouseMotionEvent(const MouseMotionEvent);
  bool DelegateMouseWheelEvent(const MouseWheelEvent);

 public:
  virtual void Render(Drawer*) override {}
  virtual void Update() override {}
  virtual bool OnMouseButtonEvent(const MouseButtonEvent) override { return false; }
  virtual bool OnMouseMotionEvent(const MouseMotionEvent) override { return false; }
  virtual bool OnMouseWheelEvent(const MouseWheelEvent) override { return false; }

 public:
  bool RenderBegin(Drawer*);
  void RenderEnd(Drawer*);
#define RENDER_BEGIN(o) if (!(o)->RenderBegin(drawer)) return;
#define RENDER_END(o)   (o)->RenderEnd(drawer);

 private:
  Rect frame_;
  Color bg_color_;
  int padding_;
  uint32_t visible_:1;
  uint32_t reserved:31;
};

#endif