#include "epd_driver.h"


#include "waveforms/epdiy_ED047TC1.h"

// Note: Alternative Waveform added by Lilygo on Oct 2021, size: 266 Kb (ED047TC1 is 37 Kb, 7 times smaller)
#if defined(CONFIG_EPD_DISPLAY_TYPE_ED047TC2)
  #include "waveforms/epdiy_ED047TC2.h"
#endif
#include "waveforms/epdiy_ED060SC4.h"
#include "waveforms/epdiy_ED060XC3.h"
#include "waveforms/epdiy_ED060SCT.h"
#include "waveforms/epdiy_ED097OC4.h"
#include "waveforms/epdiy_ED097TC2.h"
#include "waveforms/epdiy_ED133UT2.h"
#include "waveforms/epdiy_GDEW101C01.h"
