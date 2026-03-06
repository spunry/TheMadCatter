# The Mad Catter 🐾😾
A cat-clicker game where the more you click the cat, the angrier it gets… until it (maybe) jump-scares you.

This project is being built as a learning game for my son: small features, clear goals, and lots of opportunities to practice real coding skills.

---

## Game Concept
- Click the cat to increase its anger.
- Earn **Mad Points** (the shop currency) as you click.
- Buy shop items that make the cat get angry faster or generate automatic anger.
- Rebirth (prestige) up to **5 times** to unlock new shop items and scarier cat looks.
- A super-angry cat may **jump-scare** you and then reset to happy.
- Random events pop up (some make the cat angry, some make it happy).
- Spin a wheel every **15 minutes** for bonuses.
- Daily login streak rewards.

---

## Core Mechanics

### Clicking & Currency
- **Clicks**: basic progress.
- **Mad Points**: earned from clicking.
  - Rule: **Every 50 clicks = 1 Mad Point**

### Anger Meter
- Clicking increases anger.
- Some items/events increase anger faster.
- Some events/items reduce anger (happy boosts).
- If the anger reaches a high threshold, there’s a chance to trigger a **jump-scare**, then:
  - cat becomes happy again
  - (optional) apply a short cooldown before it can happen again

### Shop
Spend **Mad Points** to buy upgrades, such as:
- “Angry Click” upgrades (more anger per click)
- Items that auto-increase anger over time (clicks/sec style)

Example items:
- Dog yoyo
- Dog that chases the cat around
- Outfits (extras stored in a dresser)

### Random Pop-Up Events
Occasional objects appear on screen.
- **Anger events**: another cat (cat fight), cucumber
- **Happy events**: scratching post, cat treat

### Wheel Spin (every 15 minutes)
Possible outcomes:
- More clicks
- Make the cat angrier
- Make the cat happier
- **1%** chance: +1,000,000 clicks
- **0.5%** chance: +10,000,000,000,000 clicks/sec (10 trillion)

### Rebirth (Prestige)
- You restart progress, but gain a permanent benefit:
  - the cat stays happy longer
  - more items unlock in the shop
  - visuals get scarier each rebirth
- Limit: **5 total rebirths**

### Save/Load (Persistence)
The game should continue where you left off:
- Save clicks, mad points, upgrades, rebirth count, streak, wheel cooldown, etc.
- Auto-save on key events + on exit.

---

## Suggested Milestones (Great for Learning)
1. **Prototype clicker**
   - click counter
   - basic anger meter
2. **Mad Points**
   - earn 1 point per 50 clicks
   - simple UI display
3. **Shop v1**
   - buy an upgrade that increases “anger per click”
4. **Auto items**
   - clicks/sec or anger/sec style upgrades
5. **Random events**
   - spawn an item occasionally, click it to apply effect
6. **Wheel spin**
   - timer + outcome logic + probabilities
7. **Save system**
   - load on start, save on changes
8. **Rebirth**
   - reset + permanent progression + unlock tiers
9. **Polish**
   - animations, sounds, jump-scare, final balancing

