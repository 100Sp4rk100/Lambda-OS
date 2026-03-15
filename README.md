<img src="ressources/lambda.png" alt="Lambda logo" height="100" >

Lambda is an experimental userland for NumWorks calculators.
The userland is not finished but can be used as well.

<img src="ressources/example_os.gif" width=320 alt="Example userland">

## Functionalities

- A clock (experimental)
- Different wallpapers
- An animated wallpaper
- Custom colors
- Different themes included
- Possibility to load a theme in runtime
- Change the icons

## Launcher
To use the full potential of the userland you need to run it with the [launcher](https://raw.githubusercontent.com/100Sp4rk100/Lambda-OS/master/ressources/Lambda_OS.nwa).

To install it, go to [Numworks extern apps installer](https://my.numworks.com/apps) (you need to be login) and install the [launcher](https://raw.githubusercontent.com/100Sp4rk100/Lambda-OS/master/ressources/Lambda_OS.nwa). Then open it on your calculator and `press 1`.

The launcher allows you to [import a custom background](#dynamic-profile) without recompiling the userland.

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

The app `OFF` is useful when you use the clock because it can't run during a real power-off.

### Lambda App
It's the app to change all settings of Lambda OS. You can access it quickly by pressing the toolbox button on the home app.

You can reset the clock or activate/ deactivate the clock.
You can also switch theme :

- Lambda classic
- Lambda 2
- Town (with the animated background)
- Epsilon classic
- [Dynamic profil](#dynamic-profile)
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
- if `Activate Background` is checked you can give a background number to select an [integrated background](#adding-background). You can also check `Import background ` and then upload an image on the website with the button `Import a background ` to have it on your calculator without recompiling the userland.
- `Dynamic colors on images` change the yellow on the images with `YellowDark` that you have changed. It's useful to have custom icons without recreating all images. It's still experimental and has different results depending on colors (for example the town theme)
- If you don't use `Dynamic colors on images` you have to specify a profile for the icons : `Epsilon profile` or `Lambda profile`
- You can download and load a profile to save it

## Shortcut
It's only on the home app :
- `Toolbox` switch to the `Lambda` app
- `Ans` switch to the `Settings` app

## Python
With the `time` module you can change, get and reset the time.
All functions are available in the toolbox.
To see the syntax go [here](#set-the-clock)

## All backgrounds
To use it in a `dynamic profile` you have to put the number of the background. It works with integrated backgrounds and all the backgrounds you [add](#adding-background).

- 1
<img src="ressources/lambda_classic.png" alt="Lambda classic">

- 2
<img src="ressources/lambda_2.png" alt="Lambda 2">

- 3
<img src="ressources/town.png" alt="Town">

- 4
<img src="ressources/blossom.png" alt="Blossom">

- 5
It's an image adding in forlder `apps/theme_gestion/customs_backgrounds`.
<img src="ressources/example.png" alt="Blossom">

## Adding background
You can add a background by yourself by adding your image in PNG format in the folder `apps/theme_gestion/customs_backgrounds`.
And you have to compile the userland again.
To use the background you have to create a [dynamic profil](#dynamic-profile).
To know the number of your background you have to do : `postion in the folder` + 4. For example `apps/theme_gestion/customs_backgrounds/example.png` is in first position so we need to do : `1+4=5`. So to use the example background you need to enter 5 in [lambda theme maker](https://100sp4rk100.github.io/Lambda-Theme-Maker-WebSite/).

If you want, you can load a background without recompiling the userland by upload it with [lambda theme maker](https://100sp4rk100.github.io/Lambda-Theme-Maker-WebSite/).

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