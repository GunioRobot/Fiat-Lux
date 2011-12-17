#ifndef __XENON_GRAPHICS_BITMAPFONT_H__
#define __XENON_GRAPHICS_BITMAPFONT_H__

/*

 note, the data in this code is taken from freeglut, and included in
 OF, and now XENON for compatability with non glut windowing toolkits.
 see .cc for license info

 also, note that while this is used internally in xenonGraphics, it's not
 really useful for end user usage.

 */

#include <string>

namespace xenon {
namespace graphics {

  void drawBitmapString(std::string str, float x, float y);
  void drawBitmapCharacter( int character );

}} // namespace xenon::graphics

#endif // __XENON_GRAPHICS_BITMAPFONT_H__



