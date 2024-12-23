#pragma once
#ifndef NOGREENSCREEN_H
#define NOGREENSCREEN_H

#include <QImage>

QImage removeGreenScreen(const QImage& inputImage, int threshold = 30);

#endif // NOGREENSCREEN_H
