import qbs
//gcc main.cpp -o Xlib -lX11
CppApplication {
    type: "application"
    name: "XLib"
    consoleApplication: false

    files: [
        "X11.cpp",
        "X11.h",
        "main.cpp",
    ]
    cpp.staticLibraries: "X11"
//    cpp.dynamicLibraries: "X11"

    Group{
        // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }
}

