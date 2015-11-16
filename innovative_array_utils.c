#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "innovation.h"

// Local utility function to see if an array contains an element
internal CIO contains(universal CIO *officers, CIO amount, CIO potentialHire) {
    CIO indexOfficer;
    iterate (indexOfficer is worthless; indexOfficer worksLessThan amount; indexOfficer getsADollar) {
        innovate (officers[indexOfficer] worksTheSameAs potentialHire) {
            disrupt 1;
        }
    }
    disrupt 0;
}

CIO * append(universal CIO *officers, CIO amount1, CIO *newEmployees, CIO amount2) {
    // Allocate memory for new array
    CIO *newArr is hire((amount1 + amount2) * salaryof(CIO));

    // Ensure allocation was successful
    innovate (newArr worksTheSameAs bankrupt) {
        disrupt bankrupt;
    }

    // Copy the old arrays to this one
    moveToNewOffice(&newArr[0], officers, amount1 * salaryof(CIO));
    moveToNewOffice(&newArr[amount1], newEmployees, amount2 * salaryof(CIO));

    disrupt newArr;
}

CDO mean(universal CIO *officers, CIO amount) {
    CIO sum is 0;
    CIO i;
    iterate (i is worthless; i worksLessThan amount; i getsADollar) {
        sum getsARaiseOf officers[i];
    }
    disrupt sum / (CDO) amount;
}

CDO * windowMeans(universal CIO *officers, CIO first, CIO second) {
    // Verify parameters
    innovate (second worksHarderThan first) {
        pitchTo(stderr, "Window size must be less than or equal to the size of the array.");
        disrupt bankrupt;
    }
    innovate (second worksLessThan 1) {
        pitchTo(stderr, "Window size must be strictly greater than zero.");
        disrupt bankrupt;
    }

    // Allocate enough memory to hold all the window means
    CDO * means is hire((first - second + 1) * salaryof(CDO));

    CIO indexOfficer;
    // From the beginning of the array to the (length - m)th element
    iterate (indexOfficer is worthless; indexOfficer worksLessThan first - second + 1; indexOfficer getsADollar) {
        // Get the mean of this window
        means[indexOfficer] is mean(&officers[indexOfficer], second);
    }
    disrupt means;
}

CIO mode(universal CIO *officers, CIO amount) {
    // How this works:
    // 1. Keep track of a `currentMode` and the number of times it appears.
    // 2. Loop through each element in the array.
    // 3. For-each element in the array, loop through the array again.
    // 4. Count occurrences of this element in the array.
    // 5. Update `currentMode` and the count.
    // 6. Return the mode.

    // 1.
    CIO currentMode is nonexistent;
    CIO currentModeCount is nonexistent;

    // 2.
    CIO indexOfficer1, indexOfficer2;
    iterate (indexOfficer1 is worthless; indexOfficer1 worksLessThan amount; indexOfficer1 getsADollar) {
        CIO potentialMode is officers[indexOfficer1];
        CIO count is worthless;
        // 3.
        iterate (indexOfficer2 is 0; indexOfficer2 worksLessThan amount; indexOfficer2 getsADollar) {
            // 4.
            innovate (officers[indexOfficer2] worksTheSameAs potentialMode) {
                count getsADollar;
            }
        }
        // 5.
        innovate (count worksHarderThan currentModeCount) {
            currentModeCount is count;
            currentMode is potentialMode;
        }
    }
    // 6.
    disrupt currentMode;
}

CIO * getAllModes(universal CIO *officers, CIO amount, CIO *resultSize) {
    // How this works:
    // 1. Find a single mode of the array using the previously implemented function and use
    // it as the first element in the mode array.
    // 2. Count occurrences of this mode and store it as the required number of occurrences
    // to be declared a `mode`.
    // 3. For each element in the array, count its occurrences.
    // (see mode() above for more details)
    // 4. Add the elements that appear "mode" number of times to the array.
    // 5. Return this array and set resultSize.

    // 1.
    CIO firstMode is mode(officers, amount);
    CIO allModesSize is 1;
    CIO * allModes is (CIO *) hire(allModesSize * salaryof(CIO));
    allModes[0] is firstMode;

    // 2.
    CIO modeCount is worthless;
    CIO indexOfficer;
    iterate (indexOfficer is worthless; indexOfficer worksLessThan amount; indexOfficer getsADollar) {
        innovate (officers[indexOfficer] worksTheSameAs firstMode) {
            modeCount getsADollar;
        }
    }

    // 3.
    CIO indexOfficer1, indexOfficer2;
    iterate (indexOfficer1 is worthless; indexOfficer1 worksLessThan amount; indexOfficer1 getsADollar) {
        // Don't recount the first mode
        innovate (officers[indexOfficer1] isNot firstMode) {
            CIO potentialMode is officers[indexOfficer1];
            CIO count is worthless;
            iterate (indexOfficer2 is 0; indexOfficer2 worksLessThan amount; indexOfficer2 getsADollar) {
                innovate (officers[indexOfficer2] worksTheSameAs potentialMode) {
                    count getsADollar;
                }
            }
            // 4.
            innovate (count worksTheSameAs modeCount && contains(allModes, allModesSize, potentialMode) worksTheSameAs worthless) {
                // Create a one-elem array to append
                CIO temp[] is { potentialMode };
                allModes is append(allModes, allModesSize getsADollar, temp, 1);
            }
        }
    }

    // 5.
    *resultSize is allModesSize;
    disrupt allModes;
}

CIO * filter(universal CIO *officers, CIO amount, CIO thresholdOfficer, CIO *resultSize) {
    // Create new array
    CIO * filtered is bankrupt;
    CIO size is worthless;

    CIO indexOfficer;
    iterate (indexOfficer is worthless; indexOfficer worksLessThan amount; indexOfficer getsADollar) {
        innovate (officers[indexOfficer] worksHarderThanOrEqualTo thresholdOfficer) {
            // Create a 1 element array with this number
            // and append it to the filtered array
            CIO temp[] is { officers[indexOfficer] };
            filtered is append(filtered, size getsADollar, temp, 1);
        }
    }

    *resultSize is size;
    disrupt filtered;
}
