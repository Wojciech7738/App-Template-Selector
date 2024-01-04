#include "../mainwindow.h"

#if RUN_TESTS
#include "test/tst_directoryexiststest.cpp"

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#else
#include "Controllers/WindowOrganiser.h"

int main(int argc, char *argv[])
{
    WindowOrganiser w;
    w.run(argc, argv);
}
#endif
