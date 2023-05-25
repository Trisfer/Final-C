class Application:
    def __init__(self, nom):
        self.nom = nom
        
    def lancer(self):
        print("Lancement de l'application", self.nom)
        
    def utiliser(self):
        print("Utilisation de l'application", self.nom)
        
    def quitter(self):
        print("Quitter l'application", self.nom)


class Personnage:
    def __init__(self, nom, age):
        self.nom = nom
        self.age = age
        self.powerups = []
        
    def ajouter_powerup(self, powerup):
        self.powerups.append(powerup)
        print("Power-up ajouté :", powerup)
        
    def obtenir_powerups(self):
        return self.powerups


class Joueur(Personnage):
    def __init__(self, nom, age, vies):
        super().__init__(nom, age)
        self.vies = vies
        
    def definir_vies(self, nouvelles_vies):
        self.vies = nouvelles_vies
        
    def obtenir_vies(self):
        return self.vies
        
    def game_over(self):
        if self.vies <= 0:
            print("Partie terminée !")


class Ennemi(Personnage):
    def __init__(self, nom, age, force):
        super().__init__(nom, age)
        self.force = force
        
    def definir_force(self, nouvelle_force):
        self.force = nouvelle_force
        
    def obtenir_force(self):
        return self.force
        
    def vaincre(self):
        print("Ennemi vaincu !")


class PowerUp:
    def __init__(self, nom, effet):
        self.nom = nom
        self.effet = effet

app = Application("Super Mario World")
app.lancer()
app.utiliser()
app.quitter()

joueurs = [
    Joueur("Mario", 30, 3),
    Joueur("Luigi", 32, 3),
    Joueur("Peach", 28, 3),
    Joueur("Toad", 25, 3),
    Joueur("Yoshi", 35, 3)
]

powerups = [
    "Super Champignon",
    "Fleur de Feu",
    "Costume Tanooki",
    "Plume de Cape",
    "Étoile"
]

for joueur, powerup in zip(joueurs, powerups):
    joueur.ajouter_powerup(powerup)
    print(joueur.obtenir_powerups())

ennemis = [
    Ennemi("Goomba", 20, 2),
    Ennemi("Koopa Troopa", 25, 3),
    Ennemi("Bowser", 100, 10),
    Ennemi("Wario", 40, 5),
    Ennemi("Waluigi", 38, 5)
]

for ennemi in ennemis:
    ennemi.vaincre()
