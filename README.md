# gmsOpenNewWindow
Open two game windows at the same time in a GameMakerStudio2 project

### <b>NOTE:</b>
#### This library works on Windows OS only

# How to use
1. Compile the cpp and the header file or you can also use the pre-compiled version of the library(skip second step in this case)<br/><br/>

2. After compiling you will have to look for a dll file <br/><br/>

3. Import the dll file to your project, drag the file and drop it in the IDE<br/><br/>

4. Here you will have to define the function in GameMaker so you can use it<br/>
to do so you will write the following code in a create event of a persistent object<br/>
preferably assign it to a global variable.<br/>
```
windowCreate=external_define( "gmsOpenWindow.dll",
                                "open_another_window",
                                dll_cdecl,
                                ty_real,
                                1,
                                ty_string);
```                                
<br/>
the external_define function looks for the specified function (Second Parameter)<br/>
in the library included (First Parameter), the third parameter specifies what type of function call is it<br/>
the fourth parameter is the return type, the fifth parameter is how many parameters the function in the library takes in<br/>
and depending on how many parameters you will pass in the datatype for each parameter in the 5+nth parameter.<br/><br/>

5. Now you will make a function and call it what ever you want<br/>
For example: Create_extra_window(), and give it a single parameter<br/>
in this case its the title of the new window so we can call it "caption"<br/>
```
function create_extra_window(caption) {
    if(parameter_string(3)!=caption)
        return external_call(windowCreate, caption);
    window_set_caption(caption);
    return 0;
}
```
<br/>

### Please note that this function will not create two windows with the same caption/title<br/>as it is an error handling method to avoid creating unlimited windows
And now you can enjoy creating multiple gamemaker windows to debug your multiplayer game.

# License
The project is absolutly free to use, any feedback would be greetly appreciated<br/>
support us by subscribing to our youtube channel [GrodRiket Security](https://youtube.com/ITGEEKS)<br/>
you can contact us on [our website](http://grodriket.com/)

