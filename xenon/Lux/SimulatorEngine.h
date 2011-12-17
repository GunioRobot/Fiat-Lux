#ifndef __LUX_SIMULATOR_AUDIOCLIENT_H__
#define __LUX_SIMULATOR_AUDIOCLIENT_H__

#include <xenon/Lux/AudioClient.h>
#include <string>
#include <iostream>

namespace lux {

#define LUX_SIMULATOR_HIST_SAMPLES (5200)  // Approx 30 fps at 96 KHz audio rates
  //#define LUX_SIMULATOR_HIST_SAMPLES (48 * 50)
#define LUX_SIMULATOR_BUF_SAMPLES (LUX_SIMULATOR_HIST_SAMPLES+48000)

  typedef struct {
    float x, y, r, g, b, a;
  } bufsample_t;

  class SimulatorEngine : public AudioClient {
    int m_buf_widx;
    bufsample_t m_buffer[LUX_SIMULATOR_BUF_SAMPLES];
    int m_psize;
    int temp;

  public:

    SimulatorEngine(std::string name);
    virtual ~SimulatorEngine() {}

    // Called by Jack as new audio frames arrive
    virtual int process_callback(nframes_t nframes);

    // Methods for drawing in an OpenGL context
    void laser_color(float r, float g, float b, float ascale);
    void draw_gl();
    void resize_gl(int width, int height);

    void test() { std::cout << "It worked, I think!!\n"; }
  };

}

#endif // __LUX_SIMULATOR_AUDIOCLIENT_H__
