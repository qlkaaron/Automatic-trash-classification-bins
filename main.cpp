#include <unistd.h>
#include "PCA9685.h"

int main() {
  
  PiPCA9685::PCA9685 pca{};

  pca.set_pwm_freq(50.0);
  
  while(true) {
    pca.set_pwm_ms(0, 0.5);
    usleep(1'000'000);
    pca.set_pwm_ms(0, 2.5);
    usleep(1'000'000);
    pca.set_pwm_ms(3, 2);
    usleep(1'000'000);
    pca.set_pwm_ms(3, 1.5);
    usleep(1'000'000);
    pca.set_pwm_ms(3, 0.5);
    usleep(1'000'000);
  }
}
