# Unreal Audio DSP Collection (UE4)

![](https://user-images.githubusercontent.com/7047334/153765948-a56173f0-533c-4019-bc55-cd50cfed72d0.png)

An Unreal 4 plugin with a collection of audio effects in 2 different flavors: **SourceEffect** and **SubmixEffect**.

Currently implemented Effects:
- Gain
- Saturation (A.K.A. Drive, Distortion, Wave Shaper) (WIP, more saturation types will be added)

### Build steps:
- **Clone** repository
- Right click ***UEAudioDSPCollection.uproject*** > *Generate Visual Studio projects files*
- Open ***UEAudioDSPCollection.sln***
- **Build** Solution


### Testing the plugin:
- Open ***UEAudioDSPCollection.uproject*** (or start it from Visual Studio)
- **DemoMap** will be automatically loaded
- Go to ***Blueprints*** > ***Open Level Blueprint***
- You will see that there is Blueprint logic to trigger a sound at the Sphere location and a Timeline that will drive a parameter of the SourceEffect
- If you want to test the Submix effect simply connect the Update port from Timeline to the Set Settings node of the SubmixEffect
- Click ***Play*** button to start the Level

<br/>

![](https://user-images.githubusercontent.com/7047334/153770700-d5d52861-2c73-4b4c-b7af-7c2decc782d5.gif)
