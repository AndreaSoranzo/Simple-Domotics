#include "PaletteParser.h"

const QByteArray& ParseToPalette(QByteArray& qss, int idx) {
    switch (idx) {
        case 0:
            return qss
                // primary Colors
                .replace("-p1", "#43766C")
                .replace("-p2", "#76453B")
                .replace("-p3", "#B19470")
                .replace("-p4", "#F8FAE5")
                // secondary Colors
                .replace("-h1", "#325951")
                .replace("-h3", "#7d694f")
                .replace("-h4", "#cccebc")
                .replace("-ht", "#F8FAE5");
        case 1:
            return qss
                // primary Colors
                .replace("-p1", "#606875")
                .replace("-p2", "#6D9886")
                .replace("-p3", "#F2E7D5")
                .replace("-p4", "#F7F7F7")
                // secondary Colors
                .replace("-h1", "#393E46")
                .replace("-h3", "#8A8479")
                .replace("-h4", "#8A8888")
                .replace("-ht", "#393E46");
        default:
            return qss
                // primary Colors
                .replace("-p1", "#43766C")
                .replace("-p2", "#76453B")
                .replace("-p3", "#B19470")
                .replace("-p4", "#F8FAE5")
                // secondary Colors
                .replace("-h1", "#325951")
                .replace("-h3", "#7d694f")
                .replace("-h4", "#cccebc")
                .replace("-ht", "#F8FAE5");
    }
}