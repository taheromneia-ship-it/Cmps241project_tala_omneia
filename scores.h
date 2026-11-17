#ifndef SCORES_H
#define SCORES_H


int loadScores(const char *path, int scores[], int capacity);

int writeReport(const char *path, const int scores[], int n);

#endif
