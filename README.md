# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Rubric Discussion

### Effect of the P, I, and D components
The P in the PID controller stands for the "proportional" part. It lets the car react proportionally to the offset to the reference trajectory. This means the farther the car is away from the reference trajectory (high CTE) the bigger the steering angle will be. The parameter tau_p determines how heavy the controller reacts.

The I in the PID controller stands for the "integral" part. It handles bias which would otherwise keep the PD controller from reaching the reference trajectory. This components assures that the car will not drive on one side of the reference trajectory for a long period of time. To do this it takes into account the total sum of CTE.

The D in the PID controller stands for the "differential" part. It helps the controller to not overshoot and oscillate around the reference trajectory. Without it the car would reach the reference trajectory in an angle and then stop steering. This would lead the car to overshoot. This happens over and over again which lets the car oscillate arount the reference trajectory. The D component takes the difference between the previous and the current CTE and adjusts the steering accordingly. This lets the car approach the reference trajectory smoothly.

### Finding the Parameter Values
At first I tried to implement the Twiddle algorithm in order to optimize the control parameters. However, this did not work well because my manually set values combined with the changes by the twiddle algorithm made the car leave the road and invalidated the tuning. I then decided to use the values of the class as a reference (0.2, 0.004, 3.0) which turned out to work fine. I manually tweaked the values and figured out that it would even work with an I component of zero. However, in the end I decided to set it back to 0.004 to be able to react when drift sets in. The final parameters for the steering controller are (0.15, 0.004, 3.0).

After the steering parameters were set I startet with the controller for throttle. I took the steering angle as input for that controller so that for high steering angles the car would slow down. The direction of the steering angle doesn't matter which is why I used the absolute value. I started with the same parameters as for the steering controller, but removed the integral component which would infinitely grow when using the absolute steering angle. I increased the proportional component to be more reactive in curves. I also removed the differential component to avoid breaking for a short time often. I ended up with the parameters (0.35, 0.0, 1.5).


## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)