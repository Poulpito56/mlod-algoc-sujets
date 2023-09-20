#pragma once

enum Mois {
janvier,
fevrier,
mars,
avril,
mai,
juin,
juillet,
aout,
septembre,
octobre,
novembre,
decembre
};

struct Date {
int jour;
enum Mois mois;
int annee;
};

void initialiseDate(struct Date *d);
void afficheDate(struct Date *d);
struct Date creerDateParCopie();