# PARKOUR RUNNER 2D - Game Design Document

## 1. GAME OVERVIEW

### 1.1 Game Title
**Parkour Runner 2D**

### 1.2 Genre
Endless Runner / Action / Parkour

### 1.3 Platform
- Android (8.0+)
- iOS (13.0+)

### 1.4 Target Audience
- Age: 12-35
- Casual to Hardcore gamers
- Parkour enthusiasts
- Action game fans

### 1.5 Game Rating
PEGI 7 / ESRB Everyone 10+

### 1.6 Monetization
- Free-to-play
- In-app purchases
- Rewarded ads
- Interstitial ads
- Battle Pass

---

## 2. CORE GAMEPLAY

### 2.1 Game Objective
Player ko endlessly forward run karna hai, obstacles avoid karna hai, enemies se bachna hai, aur maximum score collect karna hai.

### 2.2 Core Loop
1. **Run** - Auto-forward movement
2. **Jump** - Obstacles avoid karna
3. **Slide** - Low obstacles se pass hona
4. **Dash** - Fast movement + enemy kill
5. **Collect** - Coins aur power-ups
6. **Survive** - Enemies aur hazards se bachna

### 2.3 Controls
| Action | Mobile | PC |
|--------|--------|-----|
| Jump | Tap / Swipe Up | Space / W |
| Slide | Swipe Down | S |
| Dash | Swipe Right | Shift |
| Grapple | Double Tap | G |

### 2.4 Scoring System
- **Distance**: 1m = 1 point
- **Coins**: 1 coin = 10 points
- **Parkour Moves**: 50-200 points
- **Combos**: 100x multiplier
- **Enemy Kill**: 100 points
- **Style Points**: Based on flair

### 2.5 Difficulty Progression
- **0-500m**: Easy (basic obstacles)
- **500-1500m**: Medium (enemies + complex obstacles)
- **1500-3000m**: Hard (traps + multiple enemies)
- **3000m+**: Expert (everything + speed increase)

---

## 3. CHARACTER SYSTEM

### 3.1 Playable Characters (10)

| # | Name | Speed | Jump | Special | Unlock |
|---|------|-------|------|---------|--------|
| 1 | Runner | Normal | Normal | None | Default |
| 2 | Ninja | Fast | High | Shadow Dash | 500 Coins |
| 3 | Assassin | Very Fast | Normal | Stealth | 1000 Coins |
| 4 | Freerunner | Normal | Very High | Wall Master | 1500 Coins |
| 5 | Cyber Runner | Fast | Normal | Hacker | 2000 Coins |
| 6 | Military | Normal | Normal | Armor | 2500 Coins |
| 7 | Acrobat | Normal | High | Flip Master | 3000 Coins |
| 8 | Shadow | Very Fast | High | Phase | 5000 Coins |
| 9 | Street Runner | Fast | Normal | Graffiti | 4000 Coins |
| 10 | Neon Phantom | Very Fast | Very High | Teleport | 10000 Coins |

### 3.2 Character Stats
- **Speed**: Movement speed multiplier
- **Jump**: Jump height multiplier
- **Stamina**: Dash/wall run duration
- **Health**: Hit points
- **Special**: Unique ability

---

## 4. PARKOUR MOVES

### 4.1 Basic Moves (Always Available)
1. **Jump** - Basic jump
2. **Double Jump** - Air mein second jump
3. **Slide** - Niche se slide
4. **Wall Jump** - Wall se bounce

### 4.2 Advanced Moves (Unlockable)
5. **Vault** - Obstacle par vault
6. **Wall Run** - Wall par run
7. **Double Wall Run** - Continuous wall run
8. **Front Flip** - Aage flip
9. **Back Flip** - Piche flip
10. **Side Flip** - Side flip
11. **Long Jump** - Lamba jump
12. **Precision Jump** - Exact landing
13. **Tic Tac** - Wall bounce
14. **Climb Up** - Up climb
15. **Underbar** - Niche se pass
16. **Dive Roll** - Dive roll
17. **Cat Leap** - Wall to wall
18. **Rope Swing** - Rope swing
19. **Zipline** - Zipline ride
20. **Dash** - Fast dash
21. **Grapple** - Grapple hook
22. **Rail Grind** - Rail grind
23. **Momentum Jump** - Speed jump

### 4.3 Move Unlocking
- **Level 1-5**: Basic moves
- **Level 6-15**: Advanced moves
- **Level 16-25**: Expert moves
- **Special**: Character-specific

---

## 5. WORLD & BIOMES

### 5.1 Biome List (14)

| # | Biome | Theme | Difficulty | Unique Feature |
|---|-------|-------|------------|----------------|
| 1 | Cyber City | Neon, Futuristic | Easy | Hacking panels |
| 2 | Neon Rooftops | Night, Lights | Easy | Glowing paths |
| 3 | Industrial Zone | Factory, Rust | Medium | Moving platforms |
| 4 | Jungle Ruins | Ancient, Nature | Medium | Vine swings |
| 5 | Snow Mountains | Cold, White | Medium | Slippery surfaces |
| 6 | Desert City | Sand, Heat | Medium | Sandstorms |
| 7 | Futuristic Labs | Clean, Tech | Hard | Laser traps |
| 8 | Underground Tunnels | Dark, Tight | Hard | Limited visibility |
| 9 | Rainy Night City | Wet, Dark | Hard | Slippery + visibility |
| 10 | Lava Factory | Hot, Dangerous | Expert | Rising lava |
| 11 | Sky Platforms | High, Clouds | Expert | Falling risk |
| 12 | Ancient Temple | Old, Traps | Expert | Triggered traps |
| 13 | Military Base | Secure, Armed | Expert | High enemy count |
| 14 | Space Colony | Zero-G, Stars | Expert | Low gravity |

### 5.2 Biome Progression
- Every 500m = New biome
- Biome repeats after all unlocked
- Difficulty increases each cycle

---

## 6. ENEMY SYSTEM

### 6.1 Enemy Types (8)

| # | Enemy | Behavior | Attack | Weakness |
|---|-------|----------|--------|----------|
| 1 | Drone | Fly, Shoot | Projectile | Dash |
| 2 | Guard | Patrol, Chase | Melee | Slide |
| 3 | Sniper Bot | Stationary | Long range | Speed |
| 4 | Robotic Dog | Fast Chase | Bite | Jump |
| 5 | Helicopter | Aerial | Bomb | Grapple |
| 6 | Rival Runner | Mirror | Parkour | Faster |
| 7 | Trap Specialist | Setup | Traps | Careful |
| 8 | Boss | Pattern | Multiple | Pattern learn |

### 6.2 AI States
- **Idle**: Waiting
- **Patrol**: Moving in pattern
- **Detect**: Player spotted
- **Chase**: Following player
- **Attack**: Attacking
- **Search**: Looking for player
- **Retreat**: Running away

---

## 7. OBJECT SYSTEM

### 7.1 Obstacles (50+)
- Static: Walls, barriers, gaps
- Moving: Platforms, trains, cranes
- Traps: Lasers, spikes, electric
- Dynamic: Collapsing floors, timed doors

### 7.2 Collectibles
- **Coin**: 10 points
- **Gold Coin**: 50 points
- **Tech Part**: Crafting material
- **Style Point**: Style ranking
- **Rare Token**: Premium currency
- **Health Pack**: Heal
- **Shield**: Temporary invincibility
- **Magnet**: Auto-collect coins
- **Score Multiplier**: 2x/3x/5x score
- **Speed Boost**: Fast run

### 7.3 Interactive Objects
- **Moving Platforms**: Auto-move
- **Boost Pads**: Speed boost
- **Bounce Pads**: High jump
- **Ziplines**: Fast travel
- **Grapple Points**: Swing
- **Checkpoints**: Save point
- **Doors**: Timed/locked
- **Switches**: Trigger events

---

## 8. PROGRESSION SYSTEM

### 8.1 Level System
- **XP**: Actions se gain
- **Levels**: 1-50
- **Rewards**: Per level unlocks

### 8.2 Upgrade System (9 Types)
| Upgrade | Max Level | Effect |
|---------|-----------|--------|
| Speed | 10 | +5% per level |
| Jump | 10 | +5% per level |
| Stamina | 10 | +10% per level |
| Combo | 10 | +10% multiplier |
| Dash | 5 | -10% cooldown |
| Magnet | 5 | +20% range |
| Shield | 5 | +2s duration |
| Score | 10 | +10% score |
| Coins | 10 | +10% coins |

### 8.3 Currency System
- **Coins**: Main currency (collect + reward)
- **Tech Parts**: Crafting (rare drops)
- **Style Points**: Style ranking
- **Rare Tokens**: Premium (IAP + rare)

---

## 9. UI/UX DESIGN

### 9.1 Screens
1. **Main Menu**: Animated background, stats, buttons
2. **Gameplay**: Minimalist HUD
3. **Pause**: Settings, resume, quit
4. **Game Over**: Score, stats, restart
5. **Shop**: Items, currencies
6. **Character Select**: Characters, stats
7. **Style Select**: Styles, preview
8. **Upgrades**: Skill tree
9. **Achievements**: Progress, rewards
10. **Leaderboard**: Rankings
11. **Settings**: Audio, graphics, controls
12. **Story**: Chapters, dialogues

### 9.2 HUD Elements
- **Score**: Top center
- **Coins**: Top right
- **Distance**: Top left
- **Combo**: Center (when active)
- **Stamina**: Bottom left
- **Health**: Bottom center
- **Power-up**: Bottom right

### 9.3 Mobile Controls
- **Left Side**: Jump area (tap/swipe up)
- **Right Side**: Slide/Dash (swipe down/right)
- **Optional**: Virtual buttons
- **Gyro**: Tilt support

---

## 10. AUDIO DESIGN

### 10.1 Music (14 tracks)
- Main menu: Cinematic
- Gameplay: Upbeat electronic
- Biome-specific: Theme matching
- Chase: Intense
- Boss: Epic
- Game over: Dramatic

### 10.2 Sound Effects (50+)
- Player: Jump, land, slide, dash, wall run, grapple
- Enemies: Shoot, alert, attack, death
- Environment: Weather, traps, platforms
- UI: Click, hover, transition
- Collectibles: Coin, power-up, rare

### 10.3 Voice Lines
- Characters: Start, jump, land, hurt, death, checkpoint
- Narrator: Story, tutorial, achievements

---

## 11. GRAPHICS

### 11.1 Art Style
- 2D silhouette (Vector-inspired)
- Modern lighting (HDR, bloom)
- Smooth animations (60fps)
- Particle effects
- Parallax backgrounds

### 11.2 Color Palette
- Cyber City: Neon blue, purple, pink
- Jungle: Green, brown, gold
- Snow: White, light blue, silver
- Lava: Red, orange, black
- Space: Dark blue, white, cyan

### 11.3 Resolution Support
- Phone: 720p to 1440p
- Tablet: 1080p to 4K
- Aspect ratios: 16:9, 18:9, 19.5:9, 20:9

---

## 12. MONETIZATION

### 12.1 In-App Purchases
| Product | Price | Content |
|---------|-------|---------|
| Coin Pack S | $0.99 | 1000 coins |
| Coin Pack M | $2.99 | 3500 coins |
| Coin Pack L | $4.99 | 6500 coins |
| Coin Pack XL | $9.99 | 15000 coins |
| Remove Ads | $4.99 | Permanent |
| Starter Pack | $1.99 | Character + Coins |
| Premium Pack | $9.99 | 3 Characters + Coins |

### 12.2 Ads
- **Rewarded**: Extra life, double coins, free items
- **Interstitial**: Every 3 runs, natural breaks
- **Banner**: Optional (bottom screen)

### 12.3 Battle Pass
- **Free Track**: Basic rewards
- **Premium Track**: $4.99/season
- **Duration**: 30 days
- **Rewards**: Characters, skins, coins, styles

### 12.4 Subscription
- **VIP**: $4.99/month
- Benefits: Daily coins, exclusive skins, no ads, priority support

---

## 13. TECHNICAL SPECIFICATIONS

### 13.1 Engine
- Unity 2022.3 LTS
- URP (Universal Render Pipeline)
- 2D Renderer

### 13.2 Performance Targets
- Minimum: 30 FPS
- Target: 60 FPS
- High-end: 120 FPS
- Load time: <3 seconds
- APK size: <150MB

### 13.3 Optimization
- Object pooling
- Chunk-based loading
- LOD system
- GPU instancing
- Texture compression
- Audio compression

### 13.4 Save System
- Local: Encrypted JSON
- Cloud: Google Play Games / Game Center
- Backup: 3 slots
- Size: <1MB

---

## 14. DEVELOPMENT ROADMAP

### Phase 1: Prototype (Weeks 1-4)
- [x] Core movement
- [x] Basic world generation
- [x] Simple UI
- [x] Placeholder art

### Phase 2: Alpha (Weeks 5-10)
- [ ] All parkour moves
- [ ] 5 biomes
- [ ] 4 enemy types
- [ ] Save system
- [ ] Basic monetization

### Phase 3: Beta (Weeks 11-16)
- [ ] All biomes
- [ ] All enemies
- [ ] Story mode
- [ ] Shop system
- [ ] Leaderboard
- [ ] Polish

### Phase 4: Launch (Weeks 17-20)
- [ ] Final testing
- [ ] Bug fixes
- [ ] Store submission
- [ ] Marketing
- [ ] Launch

### Phase 5: Post-Launch (Ongoing)
- [ ] Updates
- [ ] New content
- [ ] Events
- [ ] Community

---

## 15. TESTING PLAN

### 15.1 Testing Types
- **Unit Testing**: Individual systems
- **Integration Testing**: System interactions
- **Performance Testing**: FPS, memory, loading
- **Compatibility Testing**: Devices, OS versions
- **User Testing**: Playtesters, feedback

### 15.2 Test Cases
- Movement: All parkour moves
- World: Chunk generation, loading
- Enemies: AI behavior, attacks
- Save: Save/load, corruption
- UI: All screens, transitions
- Audio: Music, SFX, mixing
- Monetization: Purchases, ads

### 15.3 Device Testing
- Low-end: 2GB RAM, Android 8
- Mid-range: 4GB RAM, Android 10
- High-end: 8GB RAM, Android 13
- Tablets: Various sizes

---

## 16. MARKETING STRATEGY

### 16.1 Pre-Launch
- Social media teasers
- Beta signup
- Influencer outreach
- Press kit

### 16.2 Launch
- Store featuring
- Social media blast
- Influencer reviews
- Press release

### 16.3 Post-Launch
- Regular updates
- Community engagement
- Events & tournaments
- Cross-promotion

### 16.4 ASO (App Store Optimization)
- Keywords: parkour, runner, action, endless
- Screenshots: Gameplay, features
- Video: 30-second trailer
- Description: Feature-rich

---

## 17. LEGAL & COMPLIANCE

### 17.1 Privacy Policy
- Data collection
- Usage information
- Third-party services
- User rights
- GDPR compliance

### 17.2 Terms of Service
- User agreement
- Content guidelines
- Account termination
- Liability

### 17.3 COPPA Compliance
- Age verification
- Parental consent
- Data restrictions

### 17.4 Monetization Compliance
- In-app purchase disclosures
- Ad guidelines
- Subscription terms

---

## 18. APPENDIX

### 18.1 Glossary
- **Parkour**: Free-running movement
- **Chunk**: World generation unit
- **Biome**: Environment theme
- **Combo**: Consecutive moves
- **Style**: Movement flair

### 18.2 References
- Vector (game)
- Hill Climb Racing (game)
- Mirror's Edge (game)
- Canabalt (game)

### 18.3 Tools Used
- Unity 2022.3
- Visual Studio
- Photoshop/Illustrator
- FMOD/Wwise
- Git

### 18.4 Asset List
- Characters: 10 sprites + animations
- Enemies: 8 sprites + animations
- Biomes: 14 backgrounds + tiles
- UI: Complete set
- Effects: 20+ particle systems
- Audio: 14 music + 50 SFX

---

**Document Version**: 1.0
**Last Updated**: May 2026
**Author**: Game Development Team
**Status**: In Development
