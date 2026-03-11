<img src="images/lambda.png" alt="Lambda logo" height="100" >

Lambda is an experimental OS for NumWorks calculators.
The OS is not finished but can be used as well.

## Functionalities

- A clock (experimental)
- Different wallpapers
- An animated wallpaper
- Custom colors
- Different themes included
- Possibility to load a theme in runtime
- Change the icons

## Utilisation

### Set the clock
You have to use the Python script to set time.

*To set time :*
```python
import time
time.setTime(15, 2, 59) # h, m, s
```

*To get time :*
```python
import time
time.getTime()
```

*To reset time :*
```python
import time
time.resetTime()
```

The app `OFF` is useful when you use the clock because it can run during a real power-off.

### Lambda App
It's the app to change all settings of Lambda OS. You can access it quickly by pressing the toolbox button on the home app.

You can reset the clock or activate/deactivate the clock.
You can also switch theme :

- Lambda classic
- Lambda 2
- Town (with the animated background)
- Epsilon classic
- Dynamic profile
- Change the form of icons (circle/square)

## Dynamic Profile
You can load a dynamic profile with this [website](https://100sp4rk100.github.io/Lambda-Theme-Maker-WebSite/) :

- You can change all the colors that you want.
- `TextHillightColor` is used when you select an app in the home app
- `TextColor` is the color of the names of apps in the home app
- `BackgroundColor` is useful only if you don't activate the wallpaper
- `BackgroundColorHilight` is useful only if you don't activate the wallpaper and it's for when you select an app in the home app
- `Icons in a circle` change the form of icons (a circle or a square)
- `Activate Background` is to set a specific background
- `Dynamic colors on images` change the yellow on the images with `YellowDark` that you have changed. It's useful to have custom icons without recreating all images. It's still experimental and has different results depending on colors (for example the town theme)
- If you don't use `Dynamic colors on images` you have to specify a profile for the icons : `Epsilon profile` or `Lambda profile`
- You can download and load a profile to save it

After upload on the calculator you need to refresh it manually in Lambda app.

## Shortcut
It's only on the home app :
- `Toolbox` switch to the `Lambda` app
- `Ans` switch to the `Settings` app

## Python
With the `time` module you can change, get and reset the time.
All functions are available in the toolbox.

## All backgrounds
To use it in a `dynamic profile` you have to put the number of the background. It works with integrated backgrounds and all the backgrounds you add.

- 1
<img src="images/lambda_classic.png" alt="Lambda classic">

- 2
<img src="images/lambda_2.png" alt="Lambda 2">

- 3
<img src="images/town.png" alt="Town">

- 4
<img src="images/blossom.png" alt="Blossom">

- 5
It's an image adding in forlder `apps/theme_gestion/customs_backgrounds`.
<img src="images/example.png" alt="Blossom">

## Adding background
You can add a background by yourself by adding your image in PNG format in the folder `apps/theme_gestion/customs_backgrounds`.
And you have to compile the OS again.

## How to compile it
To compile it clone the repository and run :

*For calculator :*
- `make clean`
- `make MODEL=your_model userland.B.dfu`
- `python3 build/device/dfu.py -s 0x90410000:leave -D output/release/device/your_model/userland/userland.B.dfu`

*For simulator :*
- `make PLATFORM=simulator clean`
- `make PLATFORM=simulator epsilon_run`

Don't forget to change the `EPSILON_VERSION` in `build/config.mak` if necessary.