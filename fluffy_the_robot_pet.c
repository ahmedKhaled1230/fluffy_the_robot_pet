#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define STAT_MAX      10U
#define LOW_WARNING    3U
#define NAME_LEN      12U

/* mood bits */
#define BIT_ASLEEP     0U
#define BIT_HUNGRY     1U
#define BIT_SAD        2U
#define BIT_SICK       3U

#define SET_BIT(reg, n)    ((reg) |=  (uint8_t)(1U << (n)))
#define CLR_BIT(reg, n)    ((reg) &= (uint8_t)~(1U << (n)))
#define READ_BIT(reg, n)   ((uint8_t)(((reg) >> (n)) & 1U))

typedef struct {
    char     name[NAME_LEN];
    uint8_t  food;
    uint8_t  fun;
    uint8_t  energy;
    uint8_t  mood;
    uint16_t hours;
} Pet_t;

static Pet_t fluffy;


static void    hatchPet(void);
static void    drawFace(void);
static void    drawStat(const char *label, uint8_t value);
static void    feed(void);
static void    play(void);
static void    sleepPet(void);
static void    hourPasses(void);
static void    updateMood(void);
static uint8_t isHappy(void);
static void    petReport(void);

int main(void) {
    hatchPet();
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Feed\n");
        printf("2. Play\n");
        printf("3. Sleep/Wake\n");
        printf("4. Hour passes\n");
        printf("5. Show face\n");
        printf("6. Pet report\n");
        printf("0. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 0;
        }
        switch (choice) {
            case 1: feed(); break;
            case 2: play(); break;
            case 3: sleepPet(); break;
            case 4: hourPasses(); break;
            case 5: drawFace(); break;
            case 6: petReport(); break;
            case 0: break;
            default: printf("Unknown option!\n"); break;
        }
    } while (choice != 0);
    return 0;
}

static void hatchPet(void) {
    printf("Enter pet name: ");
    scanf("%11s", fluffy.name);
    fluffy.food = STAT_MAX;
    fluffy.fun = STAT_MAX;
    fluffy.energy = STAT_MAX;
    fluffy.mood = 0;
    fluffy.hours = 0;
}

static void drawFace(void) {
    printf("\n[Fluffy's Face]\n");
    if (READ_BIT(fluffy.mood, BIT_ASLEEP)) {
        printf("(-_-) zzz\n");
    } else if (READ_BIT(fluffy.mood, BIT_SICK)) {
        printf("(x_x)\n");
    } else if (READ_BIT(fluffy.mood, BIT_SAD)) {
        printf("(:-( )\n");
    } else {
        printf("(^_^)\n");
    }
}

static void drawStat(const char *label, uint8_t value) {
    printf("%s: ", label);
    for (uint8_t i = 0; i < STAT_MAX; i++) {
        putchar(i < value ? '#' : '-');
    }
    printf(" %u\n", value);
}

static void feed(void) {
    if (READ_BIT(fluffy.mood, BIT_ASLEEP)) {
        printf("Fluffy is asleep!\n");
        return;
    }
    if (fluffy.food == STAT_MAX) {
        SET_BIT(fluffy.mood, BIT_SICK);
        printf("Fluffy ate too much and got sick!\n");
        return;
    }
    fluffy.food += 3;
    if (fluffy.food > STAT_MAX) fluffy.food = STAT_MAX;
}

static void play(void) {
    if (READ_BIT(fluffy.mood, BIT_ASLEEP)) {
        printf("Fluffy is asleep!\n");
        return;
    }
    fluffy.fun += 3;
    if (fluffy.fun > STAT_MAX) fluffy.fun = STAT_MAX;
    if (fluffy.energy >= 2) {
        fluffy.energy -= 2;
    } else {
        fluffy.energy = 0;
    }
}

static void sleepPet(void) {
    if (READ_BIT(fluffy.mood, BIT_ASLEEP)) {
        CLR_BIT(fluffy.mood, BIT_ASLEEP);
        printf("Fluffy woke up!\n");
    } else {
        SET_BIT(fluffy.mood, BIT_ASLEEP);
        printf("Fluffy went to sleep!\n");
    }
}
static void    hourPasses(void){}
static void    updateMood(void){}
static uint8_t isHappy(void){}
static void    petReport(void){}