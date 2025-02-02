#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void displayJukebox() {
    printf("Welcome to Larissa's Lyric Jukebox!\n");
    printf("Please select a track from the list below:\n");
    printf("        Artist               Song                     Album            \n");
    printf("------------------------------------------------------------------------\n");
    printf(" 1:     Depeche Mode       - Enjoy the Silence      - Violator           \n");
    printf(" 2:     Madonna            - Like a prayer          - Like a Prayer      \n");
    printf(" 3:     Chris de Burgh     - Sailing Away           - Flying Colours     \n");
    printf(" 4:     Ace of Base        - The Sign               - Happy Nation       \n");
    printf(" 5:     New Order          - Truth Faith            - Substance          \n");
    printf(" 6:     Akon               - Don't Matter           - Konvicted          \n");
    printf("\n");
    printf(" 0: Quit\n");
}


void displaySongLyrics(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
        Sleep(1000); // Add a 1-second delay between lines
    }

    fclose(file);
}


int main(){
    int songNumber;
    displayJukebox();
    printf(":> ");
    scanf("%d", &songNumber);

    while(1){
        switch (songNumber) {
            case 0:
                printf("Exiting the Jukebox. Goodbye!\n");
                return 0;
            case 1:
                printf("Playing Depeche Mode - Enjoy the Silence - Violator\n");
                displaySongLyrics("aziz_larissa_enjoy_the_silence.txt");
                printf("\n\n\n");
                break;
            case 2:
                printf("Playing Madonna - Like a prayer - Like a Prayer\n");
                displaySongLyrics("aziz_larissa_like_a_prayer.txt");
                printf("\n\n\n");
                break;
            case 3:
                printf("Playing Chris de Burgh - Sailing Away - Flying Colours\n");
                displaySongLyrics("aziz_larissa_sailing_away.txt");
                printf("\n\n\n");
                break;
            case 4:
                printf("Playing Ace of Base - The Sign - Happy Nation\n");
                displaySongLyrics("aziz_larissa_the_sign.txt");
                printf("\n\n\n");
                break;
            case 5:
                printf("Playing New Order - Truth Faith - Substance\n");
                displaySongLyrics("aziz_larissa_true_faith.txt");
                printf("\n\n\n");
                break;
            case 6:
                printf("Playing Akon - Don't Matter - Konvicted\n");
                displaySongLyrics("aziz_larissa_don't_matter.txt");
                printf("\n\n\n");
                break;
            default:
                printf("Invalid choice. Please select a valid track number.\n");
        }
        displayJukebox();
        printf(":> ");
        scanf("%d", &songNumber);
    }

}
