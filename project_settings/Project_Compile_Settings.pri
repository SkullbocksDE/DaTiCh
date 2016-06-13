# -------------------------------------------------
# Compile Dir Defines
# -------------------------------------------------
    BUILD_DIR = $${PROJECT_DIR}../builds/$${PROJECT_VERSION}/

    CONFIG( debug, debug|release ):   EXECUTE_DIR = $${BUILD_DIR}execute/debug/
    CONFIG( release, debug|release ): EXECUTE_DIR = $${BUILD_DIR}execute/release/
    COMPILE_DESTINATION_DIR = $${EXECUTE_DIR}

    CONFIG( debug, debug|release ):   COMPILE_DIR = $${BUILD_DIR}compile/debug/
    CONFIG( release, debug|release ): COMPILE_DIR = $${BUILD_DIR}compile/release/
    COMPILE_MOC_DIR = $${COMPILE_DIR}moc/
    COMPILE_UI_DIR = $${COMPILE_DIR}ui/
    COMPILE_OBJECTS_DIR = $${COMPILE_DIR}obj/
    COMPILE_RCC_DIR = $${COMPILE_DIR}res/
# -------------------------------------------------


# -------------------------------------------------
# Qt Compiling Dirs
# -------------------------------------------------
    DESTDIR = $${COMPILE_DESTINATION_DIR}
    UI_DIR = $${COMPILE_UI_DIR}
    OBJECTS_DIR = $${COMPILE_OBJECTS_DIR}
    MOC_DIR = $${COMPILE_MOC_DIR}
    RCC_DIR = $${COMPILE_RCC_DIR}
# -------------------------------------------------
