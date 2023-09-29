#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"

#include <vector>
#include <string>

#include <QThread>

using namespace cv;
using namespace cv::face;

static void read_csv(const std::string &filename, std::vector<Mat> &images, std::vector<int> &labels, char separator = ';');

struct OpenCVThread : public QThread
{
    Q_OBJECT

public:
    OpenCVThread(int argc, char **argv)
        : _argc(argc), _argv(argv)
    {
    }

    void run() override;

signals:
    void resultReady(int result);

private:
    int _argc;
    char **_argv;
};