// Filename: nodePathLerps.h
// Created by:  frang (01Jun00)
// 
////////////////////////////////////////////////////////////////////

#ifndef __NODEPATHLERPS_H__
#define __NODEPATHLERPS_H__

#include <lerpfunctor.h>
#include "nodePath.h"

////////////////////////////////////////////////////////////////////
//       Class : PosLerpFunctor
// Description : Class for Lerping between positions in space
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA PosLerpFunctor : public LPoint3fLerpFunctor {
private:
  NodePath _node_path;
  NodePath _wrt_path;
  bool _is_wrt;

PUBLISHED:
  PosLerpFunctor(NodePath np, LPoint3f start, LPoint3f end)
    : LPoint3fLerpFunctor(start, end), _node_path(np), _is_wrt(false) {}
  PosLerpFunctor(NodePath np, float sx, float sy, float sz, float ex, float ey,
		 float ez) : LPoint3fLerpFunctor(LPoint3f(sx, sy, sz),
						 LPoint3f(ex, ey, ez)),
                             _node_path(np), _is_wrt(false) {}
  PosLerpFunctor(NodePath np, LPoint3f start, LPoint3f end, NodePath wrt)
    : LPoint3fLerpFunctor(start, end), _node_path(np), _is_wrt(true),
      _wrt_path(wrt) {}
  PosLerpFunctor(NodePath np, float sx, float sy, float sz, float ex, float ey,
		 float ez, NodePath wrt)
    : LPoint3fLerpFunctor(LPoint3f(sx, sy, sz), LPoint3f(ex, ey, ez)),
      _node_path(np), _is_wrt(true), _wrt_path(wrt) {}

public:
  PosLerpFunctor(const PosLerpFunctor&);
  virtual ~PosLerpFunctor(void);
  PosLerpFunctor& operator=(const PosLerpFunctor&);
  virtual void operator()(float);

public:
  // now for typehandle stuff
  static TypeHandle get_class_type(void) {
    return _type_handle;
  }
  static void init_type(void) {
    LPoint3fLerpFunctor::init_type();
    register_type(_type_handle, "PosLerpFunctor",
		  LPoint3fLerpFunctor::get_class_type());
  }
  virtual TypeHandle get_type(void) const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type(void) {
    init_type();
    return get_class_type();
  }
private:
  static TypeHandle _type_handle;
};


// evil bad bad evil HPR
////////////////////////////////////////////////////////////////////
//       Class : HprLerpFunctor
// Description : Class for Lerping between orientations in space
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA HprLerpFunctor : public LVecBase3fLerpFunctor {
private:
  NodePath _node_path;
  NodePath _wrt_path;
  bool _is_wrt;

PUBLISHED:
  HprLerpFunctor(NodePath np, LVecBase3f start, LVecBase3f end)
    : LVecBase3fLerpFunctor(start, end), _node_path(np), _is_wrt(false) {}
  HprLerpFunctor(NodePath np, float sx, float sy, float sz, float ex, float ey,
		 float ez) : LVecBase3fLerpFunctor(LVecBase3f(sx, sy, sz),
						  LVecBase3f(ex, ey, ez)),
                             _node_path(np), _is_wrt(false) {}
  HprLerpFunctor(NodePath np, LVecBase3f start, LVecBase3f end, NodePath wrt)
    : LVecBase3fLerpFunctor(start, end), _node_path(np), _is_wrt(true),
      _wrt_path(wrt) {}
  HprLerpFunctor(NodePath np, float sx, float sy, float sz, float ex, float ey,
		 float ez, NodePath wrt)
    : LVecBase3fLerpFunctor(LVecBase3f(sx, sy, sz), LVecBase3f(ex, ey, ez)),
      _node_path(np), _is_wrt(true), _wrt_path(wrt) {}

public:
  HprLerpFunctor(const HprLerpFunctor&);
  virtual ~HprLerpFunctor(void);
  HprLerpFunctor& operator=(const HprLerpFunctor&);
  virtual void operator()(float);

public:
  // now for typehandle stuff
  static TypeHandle get_class_type(void) {
    return _type_handle;
  }
  static void init_type(void) {
    LVecBase3fLerpFunctor::init_type();
    register_type(_type_handle, "HprLerpFunctor",
		  LVecBase3fLerpFunctor::get_class_type());
  }
  virtual TypeHandle get_type(void) const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type(void) {
    init_type();
    return get_class_type();
  }
private:
  static TypeHandle _type_handle;
};

////////////////////////////////////////////////////////////////////
//       Class : ColorLerpFunctor
// Description : Class for Lerping between scales
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA ScaleLerpFunctor : public LVecBase3fLerpFunctor {
private:
  NodePath _node_path;
  NodePath _wrt_path;
  bool _is_wrt;

PUBLISHED:
  ScaleLerpFunctor(NodePath np, LVecBase3f start, LVecBase3f end)
    : LVecBase3fLerpFunctor(start, end), _node_path(np), _is_wrt(false) {}
  ScaleLerpFunctor(NodePath np, float sx, float sy, float sz, float ex,
		   float ey, float ez)
    : LVecBase3fLerpFunctor(LVecBase3f(sx, sy, sz), LVecBase3f(ex, ey, ez)),
      _node_path(np), _is_wrt(false) {}
  ScaleLerpFunctor(NodePath np, LVecBase3f start, LVecBase3f end, NodePath wrt)
    : LVecBase3fLerpFunctor(start, end), _node_path(np), _is_wrt(true),
      _wrt_path(wrt) {}
  ScaleLerpFunctor(NodePath np, float sx, float sy, float sz, float ex,
		   float ey, float ez, NodePath wrt)
    : LVecBase3fLerpFunctor(LVecBase3f(sx, sy, sz), LVecBase3f(ex, ey, ez)),
      _node_path(np), _is_wrt(true), _wrt_path(wrt) {}

public:
  ScaleLerpFunctor(const ScaleLerpFunctor&);
  virtual ~ScaleLerpFunctor(void);
  ScaleLerpFunctor& operator=(const ScaleLerpFunctor&);
  virtual void operator()(float);

public:
  // now for typehandle stuff
  static TypeHandle get_class_type(void) {
    return _type_handle;
  }
  static void init_type(void) {
    LVecBase3fLerpFunctor::init_type();
    register_type(_type_handle, "ScaleLerpFunctor",
		  LVecBase3fLerpFunctor::get_class_type());
  }
  virtual TypeHandle get_type(void) const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type(void) {
    init_type();
    return get_class_type();
  }
private:
  static TypeHandle _type_handle;
};

////////////////////////////////////////////////////////////////////
//       Class : ColorLerpFunctor
// Description : Class for Lerping between colors
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA ColorLerpFunctor : public LVecBase4fLerpFunctor {
private:
  NodePath _node_path;
  NodePath _wrt_path;
  bool _is_wrt;

PUBLISHED:
  ColorLerpFunctor(NodePath np, LVecBase4f start, LVecBase4f end)
    : LVecBase4fLerpFunctor(start, end), _node_path(np), _is_wrt(false) {}
  ColorLerpFunctor(NodePath np, float sr, float sg, float sb, float sa, 
		float er, float eg, float eb, float ea) : LVecBase4fLerpFunctor(LVecBase4f(sr, sg, sb, sa),
						 LVecBase4f(er, eg, eb, ea)), _node_path(np), _is_wrt(false) {}
  ColorLerpFunctor(NodePath np, LVecBase4f start, LVecBase4f end, NodePath wrt)
    : LVecBase4fLerpFunctor(start, end), _node_path(np), _is_wrt(true),
      _wrt_path(wrt) {}
  ColorLerpFunctor(NodePath np, float sr, float sg, float sb, float sa, float er, float eg,
		 float eb, float ea, NodePath wrt)
    : LVecBase4fLerpFunctor(LVecBase4f(sr, sg, sb, sa), LVecBase4f(er, eg, eb, ea)),
      _node_path(np), _is_wrt(true), _wrt_path(wrt) {}

public:
  ColorLerpFunctor(const ColorLerpFunctor&);
  virtual ~ColorLerpFunctor(void);
  ColorLerpFunctor& operator=(const ColorLerpFunctor&);
  virtual void operator()(float);

public:
  // now for typehandle stuff
  static TypeHandle get_class_type(void) {
    return _type_handle;
  }
  static void init_type(void) {
    LVecBase4fLerpFunctor::init_type();
    register_type(_type_handle, "ColorLerpFunctor",
		  LVecBase4fLerpFunctor::get_class_type());
  }
  virtual TypeHandle get_type(void) const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type(void) {
    init_type();
    return get_class_type();
  }
private:
  static TypeHandle _type_handle;
};

////////////////////////////////////////////////////////////////////
//       Class : PosHprLerpFunctor
// Description : Class for Lerping between positions and orientations
//               in space
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA PosHprLerpFunctor : public LerpFunctor {
private:
  NodePath _node_path;
  LPoint3f _pstart;
  LPoint3f _pend;
  LPoint3f _pdiff_cache;
  LVecBase3f _hstart;
  LVecBase3f _hend;
  LVecBase3f _hdiff_cache;
  NodePath _wrt_path;
  bool _is_wrt;

PUBLISHED:
  PosHprLerpFunctor(NodePath np, LPoint3f pstart, LPoint3f pend,
		    LVecBase3f hstart, LVecBase3f hend)
    : LerpFunctor(), _node_path(np), _pstart(pstart), _pend(pend),
      _pdiff_cache(pend-pstart), _hstart(hstart), _hend(hend),
      _hdiff_cache(hend-hstart), _is_wrt(false) {}
  PosHprLerpFunctor(NodePath np, float psx, float psy, float psz, float pex,
		    float pey, float pez, float hsx, float hsy, float hsz,
		    float hex, float hey, float hez)
    : LerpFunctor(), _node_path(np), _pstart(psx, psy, psz),
      _pend(pex, pey, pez), _pdiff_cache(_pend-_pstart),
      _hstart(hsx, hsy, hsz), _hend(hex, hey, hez),
      _hdiff_cache(_hend - _hstart), _is_wrt(false) {}
  PosHprLerpFunctor(NodePath np, LPoint3f pstart, LPoint3f pend,
		    LVecBase3f hstart, LVecBase3f hend, NodePath wrt)
    : LerpFunctor(), _node_path(np), _pstart(pstart), _pend(pend),
      _pdiff_cache(pend-pstart), _hstart(hstart), _hend(hend),
      _hdiff_cache(hend-hstart), _is_wrt(true), _wrt_path(wrt) {}
  PosHprLerpFunctor(NodePath np, float psx, float psy, float psz, float pex,
		    float pey, float pez, float hsx, float hsy, float hsz,
		    float hex, float hey, float hez, NodePath wrt)
    : LerpFunctor(), _node_path(np), _pstart(psx, psy, psz),
      _pend(pex, pey, pez), _pdiff_cache(_pend-_pstart),
      _hstart(hsx, hsy, hsz), _hend(hex, hey, hez),
      _hdiff_cache(_hend - _hstart), _is_wrt(true), _wrt_path(wrt) {}

public:
  PosHprLerpFunctor(const PosHprLerpFunctor&);
  virtual ~PosHprLerpFunctor(void);
  PosHprLerpFunctor& operator=(const PosHprLerpFunctor&);
  virtual void operator()(float);

public:
  // now for typehandle stuff
  static TypeHandle get_class_type(void) {
    return _type_handle;
  }
  static void init_type(void) {
    LerpFunctor::init_type();
    register_type(_type_handle, "PosHprLerpFunctor",
		  LerpFunctor::get_class_type());
  }
  virtual TypeHandle get_type(void) const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type(void) {
    init_type();
    return get_class_type();
  }
private:
  static TypeHandle _type_handle;
};

////////////////////////////////////////////////////////////////////
//       Class : PosHprScaleLerpFunctor
// Description : Class for Lerping between position, orientation, 
//               and scale
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA PosHprScaleLerpFunctor : public LerpFunctor {
private:
  NodePath _node_path;
  LPoint3f _pstart;
  LPoint3f _pend;
  LPoint3f _pdiff_cache;
  LVecBase3f _hstart;
  LVecBase3f _hend;
  LVecBase3f _hdiff_cache;
  LVecBase3f _sstart;
  LVecBase3f _send;
  LVecBase3f _sdiff_cache;
  NodePath _wrt_path;
  bool _is_wrt;

PUBLISHED:
  PosHprScaleLerpFunctor(NodePath np, LPoint3f pstart, LPoint3f pend,
			 LVecBase3f hstart, LVecBase3f hend, LVecBase3f sstart,
			 LVecBase3f send)
    : LerpFunctor(), _node_path(np), _pstart(pstart), _pend(pend),
      _pdiff_cache(pend-pstart), _hstart(hstart), _hend(hend),
      _hdiff_cache(hend-hstart), _sstart(sstart), _send(send),
      _sdiff_cache(send-sstart), _is_wrt(false) {}
  PosHprScaleLerpFunctor(NodePath np, float psx, float psy, float psz,
			 float pex, float pey, float pez, float hsx, float hsy,
			 float hsz, float hex, float hey, float hez, float ssx,
			 float ssy, float ssz, float sex, float sey, float sez)
    : LerpFunctor(), _node_path(np), _pstart(psx, psy, psz),
      _pend(pex, pey, pez), _pdiff_cache(_pend-_pstart),
      _hstart(hsx, hsy, hsz), _hend(hex, hey, hez),
      _hdiff_cache(_hend-_hstart), _sstart(ssx, ssy, ssz),
      _send(sex, sey, sez), _sdiff_cache(_send-_sstart), _is_wrt(false) {}
  PosHprScaleLerpFunctor(NodePath np, LPoint3f pstart, LPoint3f pend,
			 LVecBase3f hstart, LVecBase3f hend, LVecBase3f sstart,
			 LVecBase3f send, NodePath wrt)
    : LerpFunctor(), _node_path(np), _pstart(pstart), _pend(pend),
      _pdiff_cache(pend-pstart), _hstart(hstart), _hend(hend),
      _hdiff_cache(hend-hstart), _sstart(sstart), _send(send),
      _sdiff_cache(send-sstart), _is_wrt(true), _wrt_path(wrt) {}
  PosHprScaleLerpFunctor(NodePath np, float psx, float psy, float psz,
			 float pex, float pey, float pez, float hsx, float hsy,
			 float hsz, float hex, float hey, float hez, float ssx,
			 float ssy, float ssz, float sex, float sey, float sez,
			 NodePath wrt)
    : LerpFunctor(), _node_path(np), _pstart(psx, psy, psz),
      _pend(pex, pey, pez), _pdiff_cache(_pend-_pstart),
      _hstart(hsx, hsy, hsz), _hend(hex, hey, hez),
      _hdiff_cache(_hend-_hstart), _sstart(ssx, ssy, ssz),
      _send(sex, sey, sez), _sdiff_cache(_send-_sstart), _is_wrt(true),
      _wrt_path(wrt) {}

public:
  PosHprScaleLerpFunctor(const PosHprScaleLerpFunctor&);
  virtual ~PosHprScaleLerpFunctor(void);
  PosHprScaleLerpFunctor& operator=(const PosHprScaleLerpFunctor&);
  virtual void operator()(float);

public:
  // now for typehandle stuff
  static TypeHandle get_class_type(void) {
    return _type_handle;
  }
  static void init_type(void) {
    LerpFunctor::init_type();
    register_type(_type_handle, "PosHprScaleLerpFunctor",
		  LerpFunctor::get_class_type());
  }
  virtual TypeHandle get_type(void) const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type(void) {
    init_type();
    return get_class_type();
  }
private:
  static TypeHandle _type_handle;
};

////////////////////////////////////////////////////////////////////
//       Class : ColorScaleLerpFunctor
// Description : Class for Lerping between color scales
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA ColorScaleLerpFunctor : public LVecBase4fLerpFunctor {
private:
  NodePath _node_path;
  NodePath _wrt_path;
  bool _is_wrt;

PUBLISHED:
  ColorScaleLerpFunctor(NodePath np, LVecBase4f start, LVecBase4f end)
    : LVecBase4fLerpFunctor(start, end), _node_path(np), _is_wrt(false) {}
  ColorScaleLerpFunctor(NodePath np, float sr, float sg, float sb, float sa, 
		float er, float eg, float eb, float ea) : LVecBase4fLerpFunctor(LVecBase4f(sr, sg, sb, sa),
						 LVecBase4f(er, eg, eb, ea)), _node_path(np), _is_wrt(false) {}
  ColorScaleLerpFunctor(NodePath np, LVecBase4f start, LVecBase4f end, NodePath wrt)
    : LVecBase4fLerpFunctor(start, end), _node_path(np), _is_wrt(true),
      _wrt_path(wrt) {}
  ColorScaleLerpFunctor(NodePath np, float sr, float sg, float sb, float sa, float er, float eg,
		 float eb, float ea, NodePath wrt)
    : LVecBase4fLerpFunctor(LVecBase4f(sr, sg, sb, sa), LVecBase4f(er, eg, eb, ea)),
      _node_path(np), _is_wrt(true), _wrt_path(wrt) {}

public:
  ColorScaleLerpFunctor(const ColorScaleLerpFunctor&);
  virtual ~ColorScaleLerpFunctor(void);
  ColorScaleLerpFunctor& operator=(const ColorScaleLerpFunctor&);
  virtual void operator()(float);

public:
  // now for typehandle stuff
  static TypeHandle get_class_type(void) {
    return _type_handle;
  }
  static void init_type(void) {
    LVecBase4fLerpFunctor::init_type();
    register_type(_type_handle, "ColorScaleLerpFunctor",
		  LVecBase4fLerpFunctor::get_class_type());
  }
  virtual TypeHandle get_type(void) const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type(void) {
    init_type();
    return get_class_type();
  }
private:
  static TypeHandle _type_handle;
};

#endif /* __NODEPATHLERPS_H__ */





