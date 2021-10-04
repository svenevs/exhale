/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2019                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
/**
 * \file
 *
 * \brief This file should be one level down in the hierarchy.
 */
#pragma once

namespace nested {
    /// The second class inside the ``nested`` namespace.
    struct two {
        /// Nesting even further: ``nested::two::params``.
        struct params {
            /// A union that occupies four bytes: http://en.cppreference.com/w/cpp/language/union
            union four_bytes {
                std::int32_t n;    ///< occupies 4 bytes
                std::uint16_t s[2];///< occupies 4 bytes
                std::uint8_t c;    ///< occupies 1 byte
            };

            /// Returns ``true`` ;)
            bool compiles() { return true; }
        };

        /// Returns ``true`` ;)
        bool compiles() { return true; }
    };

    /// A union that occupies four bytes: http://en.cppreference.com/w/cpp/language/union
    union four_bytes {
        std::int32_t n;    ///< occupies 4 bytes
        std::uint16_t s[2];///< occupies 4 bytes
        std::uint8_t c;    ///< occupies 1 byte
    };
}

#if defined(DOXYGEN_TEST_PAGES)
/**
 * \page chapter_VIII CHAPTER VIII: Mina Murray's Journal
 * _Same day, 11 o'clock p. m._--Oh, but I am tired! If it were not that I
 * had made my diary a duty I should not open it to-night. We had a lovely
 * walk. Lucy, after a while, was in gay spirits, owing, I think, to some
 * dear cows who came nosing towards us in a field close to the lighthouse,
 * and frightened the wits out of us. I believe we forgot everything
 * except, of course, personal fear, and it seemed to wipe the slate clean
 * and give us a fresh start. We had a capital "severe tea" at Robin Hood's
 * Bay in a sweet little old-fashioned inn, with a bow-window right over
 * the seaweed-covered rocks of the strand. I believe we should have
 * shocked the "New Woman" with our appetites. Men are more tolerant, bless
 * them! Then we walked home with some, or rather many, stoppages to rest,
 * and with our hearts full of a constant dread of wild bulls. Lucy was
 * really tired, and we intended to creep off to bed as soon as we could.
 * The young curate came in, however, and Mrs. Westenra asked him to stay
 * for supper. Lucy and I had both a fight for it with the dusty miller; I
 * know it was a hard fight on my part, and I am quite heroic. I think that
 * some day the bishops must get together and see about breeding up a new
 * class of curates, who don't take supper, no matter how they may be
 * pressed to, and who will know when girls are tired. Lucy is asleep and
 * breathing softly. She has more colour in her cheeks than usual, and
 * looks, oh, so sweet. If Mr. Holmwood fell in love with her seeing her
 * only in the drawing-room, I wonder what he would say if he saw her now.
 * Some of the "New Women" writers will some day start an idea that men and
 * women should be allowed to see each other asleep before proposing or
 * accepting. But I suppose the New Woman won't condescend in future to
 * accept; she will do the proposing herself. And a nice job she will make
 * of it, too! There's some consolation in that. I am so happy to-night,
 * because dear Lucy seems better. I really believe she has turned the
 * corner, and that we are over her troubles with dreaming. I should be
 * quite happy if I only knew if Jonathan.... God bless and keep him.
 *
 *        *       *       *       *       *
 *
 * _11 August, 3 a. m._--Diary again. No sleep now, so I may as well write.
 * I am too agitated to sleep. We have had such an adventure, such an
 * agonising experience. I fell asleep as soon as I had closed my diary....
 * Suddenly I became broad awake, and sat up, with a horrible sense of fear
 * upon me, and of some feeling of emptiness around me. The room was dark,
 * so I could not see Lucy's bed; I stole across and felt for her. The bed
 * was empty. I lit a match and found that she was not in the room. The
 * door was shut, but not locked, as I had left it. I feared to wake her
 * mother, who has been more than usually ill lately, so threw on some
 * clothes and got ready to look for her. As I was leaving the room it
 * struck me that the clothes she wore might give me some clue to her
 * dreaming intention. Dressing-gown would mean house; dress, outside.
 * Dressing-gown and dress were both in their places. "Thank God," I said
 * to myself, "she cannot be far, as she is only in her nightdress." I ran
 * downstairs and looked in the sitting-room. Not there! Then I looked in
 * all the other open rooms of the house, with an ever-growing fear
 * chilling my heart. Finally I came to the hall door and found it open. It
 * was not wide open, but the catch of the lock had not caught. The people
 * of the house are careful to lock the door every night, so I feared that
 * Lucy must have gone out as she was. There was no time to think of what
 * might happen; a vague, overmastering fear obscured all details. I took a
 * big, heavy shawl and ran out. The clock was striking one as I was in the
 * Crescent, and there was not a soul in sight. I ran along the North
 * Terrace, but could see no sign of the white figure which I expected. At
 * the edge of the West Cliff above the pier I looked across the harbour to
 * the East Cliff, in the hope or fear--I don't know which--of seeing Lucy
 * in our favourite seat. There was a bright full moon, with heavy black,
 * driving clouds, which threw the whole scene into a fleeting diorama of
 * light and shade as they sailed across. For a moment or two I could see
 * nothing, as the shadow of a cloud obscured St. Mary's Church and all
 * around it. Then as the cloud passed I could see the ruins of the abbey
 * coming into view; and as the edge of a narrow band of light as sharp as
 * a sword-cut moved along, the church and the churchyard became gradually
 * visible. Whatever my expectation was, it was not disappointed, for
 * there, on our favourite seat, the silver light of the moon struck a
 * half-reclining figure, snowy white. The coming of the cloud was too
 * quick for me to see much, for shadow shut down on light almost
 * immediately; but it seemed to me as though something dark stood behind
 * the seat where the white figure shone, and bent over it. What it was,
 * whether man or beast, I could not tell; I did not wait to catch another
 * glance, but flew down the steep steps to the pier and along by the
 * fish-market to the bridge, which was the only way to reach the East
 * Cliff. The town seemed as dead, for not a soul did I see; I rejoiced
 * that it was so, for I wanted no witness of poor Lucy's condition. The
 * time and distance seemed endless, and my knees trembled and my breath
 * came laboured as I toiled up the endless steps to the abbey. I must have
 * gone fast, and yet it seemed to me as if my feet were weighted with
 * lead, and as though every joint in my body were rusty. When I got almost
 * to the top I could see the seat and the white figure, for I was now
 * close enough to distinguish it even through the spells of shadow. There
 * was undoubtedly something, long and black, bending over the
 * half-reclining white figure. I called in fright, "Lucy! Lucy!" and
 * something raised a head, and from where I was I could see a white face
 * and red, gleaming eyes. Lucy did not answer, and I ran on to the
 * entrance of the churchyard. As I entered, the church was between me and
 * the seat, and for a minute or so I lost sight of her. When I came in
 * view again the cloud had passed, and the moonlight struck so brilliantly
 * that I could see Lucy half reclining with her head lying over the back
 * of the seat. She was quite alone, and there was not a sign of any living
 * thing about.
 *
 * When I bent over her I could see that she was still asleep. Her lips
 * were parted, and she was breathing--not softly as usual with her, but in
 * long, heavy gasps, as though striving to get her lungs full at every
 * breath. As I came close, she put up her hand in her sleep and pulled the
 * collar of her nightdress close around her throat. Whilst she did so
 * there came a little shudder through her, as though she felt the cold. I
 * flung the warm shawl over her, and drew the edges tight round her neck,
 * for I dreaded lest she should get some deadly chill from the night air,
 * unclad as she was. I feared to wake her all at once, so, in order to
 * have my hands free that I might help her, I fastened the shawl at her
 * throat with a big safety-pin; but I must have been clumsy in my anxiety
 * and pinched or pricked her with it, for by-and-by, when her breathing
 * became quieter, she put her hand to her throat again and moaned. When I
 * had her carefully wrapped up I put my shoes on her feet and then began
 * very gently to wake her. At first she did not respond; but gradually she
 * became more and more uneasy in her sleep, moaning and sighing
 * occasionally. At last, as time was passing fast, and, for many other
 * reasons, I wished to get her home at once, I shook her more forcibly,
 * till finally she opened her eyes and awoke. She did not seem surprised
 * to see me, as, of course, she did not realise all at once where she was.
 * Lucy always wakes prettily, and even at such a time, when her body must
 * have been chilled with cold, and her mind somewhat appalled at waking
 * unclad in a churchyard at night, she did not lose her grace. She
 * trembled a little, and clung to me; when I told her to come at once with
 * me home she rose without a word, with the obedience of a child. As we
 * passed along, the gravel hurt my feet, and Lucy noticed me wince. She
 * stopped and wanted to insist upon my taking my shoes; but I would not.
 * However, when we got to the pathway outside the churchyard, where there
 * was a puddle of water, remaining from the storm, I daubed my feet with
 * mud, using each foot in turn on the other, so that as we went home, no
 * one, in case we should meet any one, should notice my bare feet.
 *
 * Fortune favoured us, and we got home without meeting a soul. Once we saw
 * a man, who seemed not quite sober, passing along a street in front of
 * us; but we hid in a door till he had disappeared up an opening such as
 * there are here, steep little closes, or "wynds," as they call them in
 * Scotland. My heart beat so loud all the time that sometimes I thought I
 * should faint. I was filled with anxiety about Lucy, not only for her
 * health, lest she should suffer from the exposure, but for her reputation
 * in case the story should get wind. When we got in, and had washed our
 * feet, and had said a prayer of thankfulness together, I tucked her into
 * bed. Before falling asleep she asked--even implored--me not to say a
 * word to any one, even her mother, about her sleep-walking adventure. I
 * hesitated at first to promise; but on thinking of the state of her
 * mother's health, and how the knowledge of such a thing would fret her,
 * and thinking, too, of how such a story might become distorted--nay,
 * infallibly would--in case it should leak out, I thought it wiser to do
 * so. I hope I did right. I have locked the door, and the key is tied to
 * my wrist, so perhaps I shall not be again disturbed. Lucy is sleeping
 * soundly; the reflex of the dawn is high and far over the sea....
 *
 *        *       *       *       *       *
 *
 * _Same day, noon._--All goes well. Lucy slept till I woke her and seemed
 * not to have even changed her side. The adventure of the night does not
 * seem to have harmed her; on the contrary, it has benefited her, for she
 * looks better this morning than she has done for weeks. I was sorry to
 * notice that my clumsiness with the safety-pin hurt her. Indeed, it might
 * have been serious, for the skin of her throat was pierced. I must have
 * pinched up a piece of loose skin and have transfixed it, for there are
 * two little red points like pin-pricks, and on the band of her nightdress
 * was a drop of blood. When I apologised and was concerned about it, she
 * laughed and petted me, and said she did not even feel it. Fortunately it
 * cannot leave a scar, as it is so tiny.
 *
 *        *       *       *       *       *
 *
 * _Same day, night._--We passed a happy day. The air was clear, and the
 * sun bright, and there was a cool breeze. We took our lunch to Mulgrave
 * Woods, Mrs. Westenra driving by the road and Lucy and I walking by the
 * cliff-path and joining her at the gate. I felt a little sad myself, for
 * I could not but feel how _absolutely_ happy it would have been had
 * Jonathan been with me. But there! I must only be patient. In the evening
 * we strolled in the Casino Terrace, and heard some good music by Spohr
 * and Mackenzie, and went to bed early. Lucy seems more restful than she
 * has been for some time, and fell asleep at once. I shall lock the door
 * and secure the key the same as before, though I do not expect any
 * trouble to-night.
 *
 *        *       *       *       *       *
 *
 * _12 August._--My expectations were wrong, for twice during the night I
 * was wakened by Lucy trying to get out. She seemed, even in her sleep, to
 * be a little impatient at finding the door shut, and went back to bed
 * under a sort of protest. I woke with the dawn, and heard the birds
 * chirping outside of the window. Lucy woke, too, and, I was glad to see,
 * was even better than on the previous morning. All her old gaiety of
 * manner seemed to have come back, and she came and snuggled in beside me
 * and told me all about Arthur. I told her how anxious I was about
 * Jonathan, and then she tried to comfort me. Well, she succeeded
 * somewhat, for, though sympathy can't alter facts, it can help to make
 * them more bearable.
 *
 *        *       *       *       *       *
 *
 * _13 August._--Another quiet day, and to bed with the key on my wrist as
 * before. Again I awoke in the night, and found Lucy sitting up in bed,
 * still asleep, pointing to the window. I got up quietly, and pulling
 * aside the blind, looked out. It was brilliant moonlight, and the soft
 * effect of the light over the sea and sky--merged together in one great,
 * silent mystery--was beautiful beyond words. Between me and the moonlight
 * flitted a great bat, coming and going in great whirling circles. Once or
 * twice it came quite close, but was, I suppose, frightened at seeing me,
 * and flitted away across the harbour towards the abbey. When I came back
 * from the window Lucy had lain down again, and was sleeping peacefully.
 * She did not stir again all night.
 *
 *        *       *       *       *       *
 *
 * _14 August._--On the East Cliff, reading and writing all day. Lucy seems
 * to have become as much in love with the spot as I am, and it is hard to
 * get her away from it when it is time to come home for lunch or tea or
 * dinner. This afternoon she made a funny remark. We were coming home for
 * dinner, and had come to the top of the steps up from the West Pier and
 * stopped to look at the view, as we generally do. The setting sun, low
 * down in the sky, was just dropping behind Kettleness; the red light was
 * thrown over on the East Cliff and the old abbey, and seemed to bathe
 * everything in a beautiful rosy glow. We were silent for a while, and
 * suddenly Lucy murmured as if to herself:--
 *
 * "His red eyes again! They are just the same." It was such an odd
 * expression, coming _apropos_ of nothing, that it quite startled me. I
 * slewed round a little, so as to see Lucy well without seeming to stare
 * at her, and saw that she was in a half-dreamy state, with an odd look on
 * her face that I could not quite make out; so I said nothing, but
 * followed her eyes. She appeared to be looking over at our own seat,
 * whereon was a dark figure seated alone. I was a little startled myself,
 * for it seemed for an instant as if the stranger had great eyes like
 * burning flames; but a second look dispelled the illusion. The red
 * sunlight was shining on the windows of St. Mary's Church behind our
 * seat, and as the sun dipped there was just sufficient change in the
 * refraction and reflection to make it appear as if the light moved. I
 * called Lucy's attention to the peculiar effect, and she became herself
 * with a start, but she looked sad all the same; it may have been that she
 * was thinking of that terrible night up there. We never refer to it; so I
 * said nothing, and we went home to dinner. Lucy had a headache and went
 * early to bed. I saw her asleep, and went out for a little stroll myself;
 * I walked along the cliffs to the westward, and was full of sweet
 * sadness, for I was thinking of Jonathan. When coming home--it was then
 * bright moonlight, so bright that, though the front of our part of the
 * Crescent was in shadow, everything could be well seen--I threw a glance
 * up at our window, and saw Lucy's head leaning out. I thought that
 * perhaps she was looking out for me, so I opened my handkerchief and
 * waved it. She did not notice or make any movement whatever. Just then,
 * the moonlight crept round an angle of the building, and the light fell
 * on the window. There distinctly was Lucy with her head lying up against
 * the side of the window-sill and her eyes shut. She was fast asleep, and
 * by her, seated on the window-sill, was something that looked like a
 * good-sized bird. I was afraid she might get a chill, so I ran upstairs,
 * but as I came into the room she was moving back to her bed, fast
 * asleep, and breathing heavily; she was holding her hand to her throat,
 * as though to protect it from cold.
 *
 * I did not wake her, but tucked her up warmly; I have taken care that the
 * door is locked and the window securely fastened.
 *
 * She looks so sweet as she sleeps; but she is paler than is her wont, and
 * there is a drawn, haggard look under her eyes which I do not like. I
 * fear she is fretting about something. I wish I could find out what it
 * is.
 *
 *        *       *       *       *       *
 *
 * _15 August._--Rose later than usual. Lucy was languid and tired, and
 * slept on after we had been called. We had a happy surprise at breakfast.
 * Arthur's father is better, and wants the marriage to come off soon. Lucy
 * is full of quiet joy, and her mother is glad and sorry at once. Later on
 * in the day she told me the cause. She is grieved to lose Lucy as her
 * very own, but she is rejoiced that she is soon to have some one to
 * protect her. Poor dear, sweet lady! She confided to me that she has got
 * her death-warrant. She has not told Lucy, and made me promise secrecy;
 * her doctor told her that within a few months, at most, she must die, for
 * her heart is weakening. At any time, even now, a sudden shock would be
 * almost sure to kill her. Ah, we were wise to keep from her the affair of
 * the dreadful night of Lucy's sleep-walking.
 *
 *        *       *       *       *       *
 *
 * _17 August._--No diary for two whole days. I have not had the heart to
 * write. Some sort of shadowy pall seems to be coming over our happiness.
 * No news from Jonathan, and Lucy seems to be growing weaker, whilst her
 * mother's hours are numbering to a close. I do not understand Lucy's
 * fading away as she is doing. She eats well and sleeps well, and enjoys
 * the fresh air; but all the time the roses in her cheeks are fading, and
 * she gets weaker and more languid day by day; at night I hear her gasping
 * as if for air. I keep the key of our door always fastened to my wrist at
 * night, but she gets up and walks about the room, and sits at the open
 * window. Last night I found her leaning out when I woke up, and when I
 * tried to wake her I could not; she was in a faint. When I managed to
 * restore her she was as weak as water, and cried silently between long,
 * painful struggles for breath. When I asked her how she came to be at the
 * window she shook her head and turned away. I trust her feeling ill may
 * not be from that unlucky prick of the safety-pin. I looked at her throat
 * just now as she lay asleep, and the tiny wounds seem not to have healed.
 * They are still open, and, if anything, larger than before, and the
 * edges of them are faintly white. They are like little white dots with
 * red centres. Unless they heal within a day or two, I shall insist on the
 * doctor seeing about them.
 *
 *
 * _Letter, Samuel F. Billington & Son, Solicitors, Whitby, to Messrs.
 * Carter, Paterson & Co., London._
 *
 * "_17 August._
 *
 * "Dear Sirs,--
 *
 * "Herewith please receive invoice of goods sent by Great Northern
 * Railway. Same are to be delivered at Carfax, near Purfleet, immediately
 * on receipt at goods station King's Cross. The house is at present empty,
 * but enclosed please find keys, all of which are labelled.
 *
 * "You will please deposit the boxes, fifty in number, which form the
 * consignment, in the partially ruined building forming part of the house
 * and marked 'A' on rough diagram enclosed. Your agent will easily
 * recognise the locality, as it is the ancient chapel of the mansion. The
 * goods leave by the train at 9:30 to-night, and will be due at King's
 * Cross at 4:30 to-morrow afternoon. As our client wishes the delivery
 * made as soon as possible, we shall be obliged by your having teams ready
 * at King's Cross at the time named and forthwith conveying the goods to
 * destination. In order to obviate any delays possible through any routine
 * requirements as to payment in your departments, we enclose cheque
 * herewith for ten pounds (£10), receipt of which please acknowledge.
 * Should the charge be less than this amount, you can return balance; if
 * greater, we shall at once send cheque for difference on hearing from
 * you. You are to leave the keys on coming away in the main hall of the
 * house, where the proprietor may get them on his entering the house by
 * means of his duplicate key.
 *
 * "Pray do not take us as exceeding the bounds of business courtesy in
 * pressing you in all ways to use the utmost expedition.
 *
 * _"We are, dear Sirs,
 *
 * "Faithfully yours,
 *
 * "SAMUEL F. BILLINGTON & SON."_
 *
 *
 * _Letter, Messrs. Carter, Paterson & Co., London, to Messrs. Billington &
 * Son, Whitby._
 *
 * "_21 August._
 *
 * "Dear Sirs,--
 *
 * "We beg to acknowledge £10 received and to return cheque £1 17s. 9d,
 * amount of overplus, as shown in receipted account herewith. Goods are
 * delivered in exact accordance with instructions, and keys left in parcel
 * in main hall, as directed.
 *
 * "We are, dear Sirs,
 *
 * "Yours respectfully.
 *
 * "_Pro_ CARTER, PATERSON & CO."
 *
 *
 * _Mina Murray's Journal._
 *
 * _18 August._--I am happy to-day, and write sitting on the seat in the
 * churchyard. Lucy is ever so much better. Last night she slept well all
 * night, and did not disturb me once. The roses seem coming back already
 * to her cheeks, though she is still sadly pale and wan-looking. If she
 * were in any way anæmic I could understand it, but she is not. She is in
 * gay spirits and full of life and cheerfulness. All the morbid reticence
 * seems to have passed from her, and she has just reminded me, as if I
 * needed any reminding, of _that_ night, and that it was here, on this
 * very seat, I found her asleep. As she told me she tapped playfully with
 * the heel of her boot on the stone slab and said:--
 *
 * "My poor little feet didn't make much noise then! I daresay poor old Mr.
 * Swales would have told me that it was because I didn't want to wake up
 * Geordie." As she was in such a communicative humour, I asked her if she
 * had dreamed at all that night. Before she answered, that sweet, puckered
 * look came into her forehead, which Arthur--I call him Arthur from her
 * habit--says he loves; and, indeed, I don't wonder that he does. Then she
 * went on in a half-dreaming kind of way, as if trying to recall it to
 * herself:--
 *
 * "I didn't quite dream; but it all seemed to be real. I only wanted to be
 * here in this spot--I don't know why, for I was afraid of something--I
 * don't know what. I remember, though I suppose I was asleep, passing
 * through the streets and over the bridge. A fish leaped as I went by, and
 * I leaned over to look at it, and I heard a lot of dogs howling--the
 * whole town seemed as if it must be full of dogs all howling at once--as
 * I went up the steps. Then I had a vague memory of something long and
 * dark with red eyes, just as we saw in the sunset, and something very
 * sweet and very bitter all around me at once; and then I seemed sinking
 * into deep green water, and there was a singing in my ears, as I have
 * heard there is to drowning men; and then everything seemed passing away
 * from me; my soul seemed to go out from my body and float about the air.
 * I seem to remember that once the West Lighthouse was right under me,
 * and then there was a sort of agonising feeling, as if I were in an
 * earthquake, and I came back and found you shaking my body. I saw you do
 * it before I felt you."
 *
 * Then she began to laugh. It seemed a little uncanny to me, and I
 * listened to her breathlessly. I did not quite like it, and thought it
 * better not to keep her mind on the subject, so we drifted on to other
 * subjects, and Lucy was like her old self again. When we got home the
 * fresh breeze had braced her up, and her pale cheeks were really more
 * rosy. Her mother rejoiced when she saw her, and we all spent a very
 * happy evening together.
 *
 *        *       *       *       *       *
 *
 * _19 August._--Joy, joy, joy! although not all joy. At last, news of
 * Jonathan. The dear fellow has been ill; that is why he did not write. I
 * am not afraid to think it or say it, now that I know. Mr. Hawkins sent
 * me on the letter, and wrote himself, oh, so kindly. I am to leave in the
 * morning and go over to Jonathan, and to help to nurse him if necessary,
 * and to bring him home. Mr. Hawkins says it would not be a bad thing if
 * we were to be married out there. I have cried over the good Sister's
 * letter till I can feel it wet against my bosom, where it lies. It is of
 * Jonathan, and must be next my heart, for he is _in_ my heart. My journey
 * is all mapped out, and my luggage ready. I am only taking one change of
 * dress; Lucy will bring my trunk to London and keep it till I send for
 * it, for it may be that ... I must write no more; I must keep it to say
 * to Jonathan, my husband. The letter that he has seen and touched must
 * comfort me till we meet.
 *
 *
 * _Letter, Sister Agatha, Hospital of St. Joseph and Ste. Mary,
 * Buda-Pesth, to Miss Wilhelmina Murray._
 *
 * "_12 August._
 *
 * "Dear Madam,--
 *
 * "I write by desire of Mr. Jonathan Harker, who is himself not strong
 * enough to write, though progressing well, thanks to God and St. Joseph
 * and Ste. Mary. He has been under our care for nearly six weeks,
 * suffering from a violent brain fever. He wishes me to convey his love,
 * and to say that by this post I write for him to Mr. Peter Hawkins,
 * Exeter, to say, with his dutiful respects, that he is sorry for his
 * delay, and that all of his work is completed. He will require some few
 * weeks' rest in our sanatorium in the hills, but will then return. He
 * wishes me to say that he has not sufficient money with him, and that he
 * would like to pay for his staying here, so that others who need shall
 * not be wanting for help.
 *
 * "Believe me,
 *
 * "Yours, with sympathy and all blessings,
 *
 * "SISTER AGATHA.
 *
 * "P. S.--My patient being asleep, I open this to let you know something
 * more. He has told me all about you, and that you are shortly to be his
 * wife. All blessings to you both! He has had some fearful shock--so says
 * our doctor--and in his delirium his ravings have been dreadful; of
 * wolves and poison and blood; of ghosts and demons; and I fear to say of
 * what. Be careful with him always that there may be nothing to excite him
 * of this kind for a long time to come; the traces of such an illness as
 * his do not lightly die away. We should have written long ago, but we
 * knew nothing of his friends, and there was on him nothing that any one
 * could understand. He came in the train from Klausenburg, and the guard
 * was told by the station-master there that he rushed into the station
 * shouting for a ticket for home. Seeing from his violent demeanour that
 * he was English, they gave him a ticket for the furthest station on the
 * way thither that the train reached.
 *
 * "Be assured that he is well cared for. He has won all hearts by his
 * sweetness and gentleness. He is truly getting on well, and I have no
 * doubt will in a few weeks be all himself. But be careful of him for
 * safety's sake. There are, I pray God and St. Joseph and Ste. Mary, many,
 * many, happy years for you both."
 *
 *
 * _Dr. Seward's Diary._
 *
 * _19 August._--Strange and sudden change in Renfield last night. About
 * eight o'clock he began to get excited and sniff about as a dog does when
 * setting. The attendant was struck by his manner, and knowing my interest
 * in him, encouraged him to talk. He is usually respectful to the
 * attendant and at times servile; but to-night, the man tells me, he was
 * quite haughty. Would not condescend to talk with him at all. All he
 * would say was:--
 *
 *      "I don't want to talk to you: you don't count now; the Master is at
 *      hand."
 *
 * The attendant thinks it is some sudden form of religious mania which has
 * seized him. If so, we must look out for squalls, for a strong man with
 * homicidal and religious mania at once might be dangerous. The
 * combination is a dreadful one. At nine o'clock I visited him myself. His
 * attitude to me was the same as that to the attendant; in his sublime
 * self-feeling the difference between myself and attendant seemed to him
 * as nothing. It looks like religious mania, and he will soon think that
 * he himself is God. These infinitesimal distinctions between man and man
 * are too paltry for an Omnipotent Being. How these madmen give themselves
 * away! The real God taketh heed lest a sparrow fall; but the God created
 * from human vanity sees no difference between an eagle and a sparrow. Oh,
 * if men only knew!
 *
 * For half an hour or more Renfield kept getting excited in greater and
 * greater degree. I did not pretend to be watching him, but I kept strict
 * observation all the same. All at once that shifty look came into his
 * eyes which we always see when a madman has seized an idea, and with it
 * the shifty movement of the head and back which asylum attendants come to
 * know so well. He became quite quiet, and went and sat on the edge of his
 * bed resignedly, and looked into space with lack-lustre eyes. I thought I
 * would find out if his apathy were real or only assumed, and tried to
 * lead him to talk of his pets, a theme which had never failed to excite
 * his attention. At first he made no reply, but at length said testily:--
 *
 * "Bother them all! I don't care a pin about them."
 *
 * "What?" I said. "You don't mean to tell me you don't care about
 * spiders?" (Spiders at present are his hobby and the note-book is filling
 * up with columns of small figures.) To this he answered enigmatically:--
 *
 * "The bride-maidens rejoice the eyes that wait the coming of the bride;
 * but when the bride draweth nigh, then the maidens shine not to the eyes
 * that are filled."
 *
 * He would not explain himself, but remained obstinately seated on his bed
 * all the time I remained with him.
 *
 * I am weary to-night and low in spirits. I cannot but think of Lucy, and
 * how different things might have been. If I don't sleep at once, chloral,
 * the modern Morpheus--C_{2}HCl_{3}O. H_{2}O! I must be careful not to let
 * it grow into a habit. No, I shall take none to-night! I have thought of
 * Lucy, and I shall not dishonour her by mixing the two. If need be,
 * to-night shall be sleepless....
 *
 *        *       *       *       *       *
 *
 * _Later._--Glad I made the resolution; gladder that I kept to it. I had
 * lain tossing about, and had heard the clock strike only twice, when the
 * night-watchman came to me, sent up from the ward, to say that Renfield
 * had escaped. I threw on my clothes and ran down at once; my patient is
 * too dangerous a person to be roaming about. Those ideas of his might
 * work out dangerously with strangers. The attendant was waiting for me.
 * He said he had seen him not ten minutes before, seemingly asleep in his
 * bed, when he had looked through the observation-trap in the door. His
 * attention was called by the sound of the window being wrenched out. He
 * ran back and saw his feet disappear through the window, and had at once
 * sent up for me. He was only in his night-gear, and cannot be far off.
 * The attendant thought it would be more useful to watch where he should
 * go than to follow him, as he might lose sight of him whilst getting out
 * of the building by the door. He is a bulky man, and couldn't get through
 * the window. I am thin, so, with his aid, I got out, but feet foremost,
 * and, as we were only a few feet above ground, landed unhurt. The
 * attendant told me the patient had gone to the left, and had taken a
 * straight line, so I ran as quickly as I could. As I got through the belt
 * of trees I saw a white figure scale the high wall which separates our
 * grounds from those of the deserted house.
 *
 * I ran back at once, told the watchman to get three or four men
 * immediately and follow me into the grounds of Carfax, in case our friend
 * might be dangerous. I got a ladder myself, and crossing the wall,
 * dropped down on the other side. I could see Renfield's figure just
 * disappearing behind the angle of the house, so I ran after him. On the
 * far side of the house I found him pressed close against the old
 * ironbound oak door of the chapel. He was talking, apparently to some
 * one, but I was afraid to go near enough to hear what he was saying, lest
 * I might frighten him, and he should run off. Chasing an errant swarm of
 * bees is nothing to following a naked lunatic, when the fit of escaping
 * is upon him! After a few minutes, however, I could see that he did not
 * take note of anything around him, and so ventured to draw nearer to
 * him--the more so as my men had now crossed the wall and were closing him
 * in. I heard him say:--
 *
 * "I am here to do Your bidding, Master. I am Your slave, and You will
 * reward me, for I shall be faithful. I have worshipped You long and afar
 * off. Now that You are near, I await Your commands, and You will not pass
 * me by, will You, dear Master, in Your distribution of good things?"
 *
 * He _is_ a selfish old beggar anyhow. He thinks of the loaves and fishes
 * even when he believes he is in a Real Presence. His manias make a
 * startling combination. When we closed in on him he fought like a tiger.
 * He is immensely strong, for he was more like a wild beast than a man. I
 * never saw a lunatic in such a paroxysm of rage before; and I hope I
 * shall not again. It is a mercy that we have found out his strength and
 * his danger in good time. With strength and determination like his, he
 * might have done wild work before he was caged. He is safe now at any
 * rate. Jack Sheppard himself couldn't get free from the strait-waistcoat
 * that keeps him restrained, and he's chained to the wall in the padded
 * room. His cries are at times awful, but the silences that follow are
 * more deadly still, for he means murder in every turn and movement.
 *
 * Just now he spoke coherent words for the first time:--
 *
 * "I shall be patient, Master. It is coming--coming--coming!"
 *
 * So I took the hint, and came too. I was too excited to sleep, but this
 * diary has quieted me, and I feel I shall get some sleep to-night.
 */
/*                                                                             *
 **                                                                           **
 ***                                                                         ***
 ****                                                                       ****
 *****                                                                     *****
 ******                                                                   ******
 *******                                                                 *******
 ******                                                                   ******
 *****                                                                     *****
 ****                                                                       ****
 ***                                                                         ***
 **                                                                           **
 *                                                                             */
/**
 * \page chapter_IX CHAPTER IX: Mina Murray's Journal
 * _Letter, Mina Harker to Lucy Westenra._
 *
 * "_Buda-Pesth, 24 August._
 *
 * "My dearest Lucy,--
 *
 * "I know you will be anxious to hear all that has happened since we
 * parted at the railway station at Whitby. Well, my dear, I got to Hull
 * all right, and caught the boat to Hamburg, and then the train on here. I
 * feel that I can hardly recall anything of the journey, except that I
 * knew I was coming to Jonathan, and, that as I should have to do some
 * nursing, I had better get all the sleep I could.... I found my dear one,
 * oh, so thin and pale and weak-looking. All the resolution has gone out
 * of his dear eyes, and that quiet dignity which I told you was in his
 * face has vanished. He is only a wreck of himself, and he does not
 * remember anything that has happened to him for a long time past. At
 * least, he wants me to believe so, and I shall never ask. He has had some
 * terrible shock, and I fear it might tax his poor brain if he were to try
 * to recall it. Sister Agatha, who is a good creature and a born nurse,
 * tells me that he raved of dreadful things whilst he was off his head. I
 * wanted her to tell me what they were; but she would only cross herself,
 * and say she would never tell; that the ravings of the sick were the
 * secrets of God, and that if a nurse through her vocation should hear
 * them, she should respect her trust. She is a sweet, good soul, and the
 * next day, when she saw I was troubled, she opened up the subject again,
 * and after saying that she could never mention what my poor dear raved
 * about, added: 'I can tell you this much, my dear: that it was not about
 * anything which he has done wrong himself; and you, as his wife to be,
 * have no cause to be concerned. He has not forgotten you or what he owes
 * to you. His fear was of great and terrible things, which no mortal can
 * treat of.' I do believe the dear soul thought I might be jealous lest my
 * poor dear should have fallen in love with any other girl. The idea of
 * _my_ being jealous about Jonathan! And yet, my dear, let me whisper, I
 * felt a thrill of joy through me when I _knew_ that no other woman was a
 * cause of trouble. I am now sitting by his bedside, where I can see his
 * face while he sleeps. He is waking!...
 *
 * "When he woke he asked me for his coat, as he wanted to get something
 * from the pocket; I asked Sister Agatha, and she brought all his things.
 * I saw that amongst them was his note-book, and was going to ask him to
 * let me look at it--for I knew then that I might find some clue to his
 * trouble--but I suppose he must have seen my wish in my eyes, for he sent
 * me over to the window, saying he wanted to be quite alone for a moment.
 * Then he called me back, and when I came he had his hand over the
 * note-book, and he said to me very solemnly:--
 *
 * "'Wilhelmina'--I knew then that he was in deadly earnest, for he has
 * never called me by that name since he asked me to marry him--'you know,
 * dear, my ideas of the trust between husband and wife: there should be no
 * secret, no concealment. I have had a great shock, and when I try to
 * think of what it is I feel my head spin round, and I do not know if it
 * was all real or the dreaming of a madman. You know I have had brain
 * fever, and that is to be mad. The secret is here, and I do not want to
 * know it. I want to take up my life here, with our marriage.' For, my
 * dear, we had decided to be married as soon as the formalities are
 * complete. 'Are you willing, Wilhelmina, to share my ignorance? Here is
 * the book. Take it and keep it, read it if you will, but never let me
 * know; unless, indeed, some solemn duty should come upon me to go back to
 * the bitter hours, asleep or awake, sane or mad, recorded here.' He fell
 * back exhausted, and I put the book under his pillow, and kissed him. I
 * have asked Sister Agatha to beg the Superior to let our wedding be this
 * afternoon, and am waiting her reply....
 *
 *        *       *       *       *       *
 *
 * "She has come and told me that the chaplain of the English mission
 * church has been sent for. We are to be married in an hour, or as soon
 * after as Jonathan awakes....
 *
 *        *       *       *       *       *
 *
 * "Lucy, the time has come and gone. I feel very solemn, but very, very
 * happy. Jonathan woke a little after the hour, and all was ready, and he
 * sat up in bed, propped up with pillows. He answered his 'I will' firmly
 * and strongly. I could hardly speak; my heart was so full that even those
 * words seemed to choke me. The dear sisters were so kind. Please God, I
 * shall never, never forget them, nor the grave and sweet responsibilities
 * I have taken upon me. I must tell you of my wedding present. When the
 * chaplain and the sisters had left me alone with my husband--oh, Lucy, it
 * is the first time I have written the words 'my husband'--left me alone
 * with my husband, I took the book from under his pillow, and wrapped it
 * up in white paper, and tied it with a little bit of pale blue ribbon
 * which was round my neck, and sealed it over the knot with sealing-wax,
 * and for my seal I used my wedding ring. Then I kissed it and showed it
 * to my husband, and told him that I would keep it so, and then it would
 * be an outward and visible sign for us all our lives that we trusted each
 * other; that I would never open it unless it were for his own dear sake
 * or for the sake of some stern duty. Then he took my hand in his, and oh,
 * Lucy, it was the first time he took _his wife's_ hand, and said that it
 * was the dearest thing in all the wide world, and that he would go
 * through all the past again to win it, if need be. The poor dear meant to
 * have said a part of the past, but he cannot think of time yet, and I
 * shall not wonder if at first he mixes up not only the month, but the
 * year.
 *
 * "Well, my dear, what could I say? I could only tell him that I was the
 * happiest woman in all the wide world, and that I had nothing to give him
 * except myself, my life, and my trust, and that with these went my love
 * and duty for all the days of my life. And, my dear, when he kissed me,
 * and drew me to him with his poor weak hands, it was like a very solemn
 * pledge between us....
 *
 * "Lucy dear, do you know why I tell you all this? It is not only because
 * it is all sweet to me, but because you have been, and are, very dear to
 * me. It was my privilege to be your friend and guide when you came from
 * the schoolroom to prepare for the world of life. I want you to see now,
 * and with the eyes of a very happy wife, whither duty has led me; so that
 * in your own married life you too may be all happy as I am. My dear,
 * please Almighty God, your life may be all it promises: a long day of
 * sunshine, with no harsh wind, no forgetting duty, no distrust. I must
 * not wish you no pain, for that can never be; but I do hope you will be
 * _always_ as happy as I am _now_. Good-bye, my dear. I shall post this at
 * once, and, perhaps, write you very soon again. I must stop, for Jonathan
 * is waking--I must attend to my husband!
 *
 * "Your ever-loving
 *
 * "MINA HARKER."
 *
 *
 * _Letter, Lucy Westenra to Mina Harker._
 *
 * "_Whitby, 30 August._
 *
 * "My dearest Mina,--
 *
 * "Oceans of love and millions of kisses, and may you soon be in your own
 * home with your husband. I wish you could be coming home soon enough to
 * stay with us here. The strong air would soon restore Jonathan; it has
 * quite restored me. I have an appetite like a cormorant, am full of
 * life, and sleep well. You will be glad to know that I have quite given
 * up walking in my sleep. I think I have not stirred out of my bed for a
 * week, that is when I once got into it at night. Arthur says I am getting
 * fat. By the way, I forgot to tell you that Arthur is here. We have such
 * walks and drives, and rides, and rowing, and tennis, and fishing
 * together; and I love him more than ever. He _tells_ me that he loves me
 * more, but I doubt that, for at first he told me that he couldn't love me
 * more than he did then. But this is nonsense. There he is, calling to me.
 * So no more just at present from your loving
 *
 * "LUCY.
 *
 * "P. S.--Mother sends her love. She seems better, poor dear. "P. P.
 * S.--We are to be married on 28 September."
 *
 *
 * _Dr. Seward's Diary._
 *
 * _20 August._--The case of Renfield grows even more interesting. He has
 * now so far quieted that there are spells of cessation from his passion.
 * For the first week after his attack he was perpetually violent. Then one
 * night, just as the moon rose, he grew quiet, and kept murmuring to
 * himself: "Now I can wait; now I can wait." The attendant came to tell
 * me, so I ran down at once to have a look at him. He was still in the
 * strait-waistcoat and in the padded room, but the suffused look had gone
 * from his face, and his eyes had something of their old pleading--I might
 * almost say, "cringing"--softness. I was satisfied with his present
 * condition, and directed him to be relieved. The attendants hesitated,
 * but finally carried out my wishes without protest. It was a strange
 * thing that the patient had humour enough to see their distrust, for,
 * coming close to me, he said in a whisper, all the while looking
 * furtively at them:--
 *
 * "They think I could hurt you! Fancy _me_ hurting _you_! The fools!"
 *
 * It was soothing, somehow, to the feelings to find myself dissociated
 * even in the mind of this poor madman from the others; but all the same I
 * do not follow his thought. Am I to take it that I have anything in
 * common with him, so that we are, as it were, to stand together; or has
 * he to gain from me some good so stupendous that my well-being is needful
 * to him? I must find out later on. To-night he will not speak. Even the
 * offer of a kitten or even a full-grown cat will not tempt him. He will
 * only say: "I don't take any stock in cats. I have more to think of now,
 * and I can wait; I can wait."
 *
 * After a while I left him. The attendant tells me that he was quiet
 * until just before dawn, and that then he began to get uneasy, and at
 * length violent, until at last he fell into a paroxysm which exhausted
 * him so that he swooned into a sort of coma.
 *
 *        *       *       *       *       *
 *
 * ... Three nights has the same thing happened--violent all day then quiet
 * from moonrise to sunrise. I wish I could get some clue to the cause. It
 * would almost seem as if there was some influence which came and went.
 * Happy thought! We shall to-night play sane wits against mad ones. He
 * escaped before without our help; to-night he shall escape with it. We
 * shall give him a chance, and have the men ready to follow in case they
 * are required....
 *
 *        *       *       *       *       *
 *
 * _23 August._--"The unexpected always happens." How well Disraeli knew
 * life. Our bird when he found the cage open would not fly, so all our
 * subtle arrangements were for nought. At any rate, we have proved one
 * thing; that the spells of quietness last a reasonable time. We shall in
 * future be able to ease his bonds for a few hours each day. I have given
 * orders to the night attendant merely to shut him in the padded room,
 * when once he is quiet, until an hour before sunrise. The poor soul's
 * body will enjoy the relief even if his mind cannot appreciate it. Hark!
 * The unexpected again! I am called; the patient has once more escaped.
 *
 *        *       *       *       *       *
 *
 * _Later._--Another night adventure. Renfield artfully waited until the
 * attendant was entering the room to inspect. Then he dashed out past him
 * and flew down the passage. I sent word for the attendants to follow.
 * Again he went into the grounds of the deserted house, and we found him
 * in the same place, pressed against the old chapel door. When he saw me
 * he became furious, and had not the attendants seized him in time, he
 * would have tried to kill me. As we were holding him a strange thing
 * happened. He suddenly redoubled his efforts, and then as suddenly grew
 * calm. I looked round instinctively, but could see nothing. Then I caught
 * the patient's eye and followed it, but could trace nothing as it looked
 * into the moonlit sky except a big bat, which was flapping its silent and
 * ghostly way to the west. Bats usually wheel and flit about, but this one
 * seemed to go straight on, as if it knew where it was bound for or had
 * some intention of its own. The patient grew calmer every instant, and
 * presently said:--
 *
 * "You needn't tie me; I shall go quietly!" Without trouble we came back
 * to the house. I feel there is something ominous in his calm, and shall
 * not forget this night....
 *
 *
 * _Lucy Westenra's Diary_
 *
 * _Hillingham, 24 August._--I must imitate Mina, and keep writing things
 * down. Then we can have long talks when we do meet. I wonder when it will
 * be. I wish she were with me again, for I feel so unhappy. Last night I
 * seemed to be dreaming again just as I was at Whitby. Perhaps it is the
 * change of air, or getting home again. It is all dark and horrid to me,
 * for I can remember nothing; but I am full of vague fear, and I feel so
 * weak and worn out. When Arthur came to lunch he looked quite grieved
 * when he saw me, and I hadn't the spirit to try to be cheerful. I wonder
 * if I could sleep in mother's room to-night. I shall make an excuse and
 * try.
 *
 *        *       *       *       *       *
 *
 * _25 August._--Another bad night. Mother did not seem to take to my
 * proposal. She seems not too well herself, and doubtless she fears to
 * worry me. I tried to keep awake, and succeeded for a while; but when the
 * clock struck twelve it waked me from a doze, so I must have been falling
 * asleep. There was a sort of scratching or flapping at the window, but I
 * did not mind it, and as I remember no more, I suppose I must then have
 * fallen asleep. More bad dreams. I wish I could remember them. This
 * morning I am horribly weak. My face is ghastly pale, and my throat pains
 * me. It must be something wrong with my lungs, for I don't seem ever to
 * get air enough. I shall try to cheer up when Arthur comes, or else I
 * know he will be miserable to see me so.
 *
 *
 * _Letter, Arthur Holmwood to Dr. Seward._
 *
 * "_Albemarle Hotel, 31 August._
 *
 * "My dear Jack,--
 *
 * "I want you to do me a favour. Lucy is ill; that is, she has no special
 * disease, but she looks awful, and is getting worse every day. I have
 * asked her if there is any cause; I do not dare to ask her mother, for to
 * disturb the poor lady's mind about her daughter in her present state of
 * health would be fatal. Mrs. Westenra has confided to me that her doom is
 * spoken--disease of the heart--though poor Lucy does not know it yet. I
 * am sure that there is something preying on my dear girl's mind. I am
 * almost distracted when I think of her; to look at her gives me a pang. I
 * told her I should ask you to see her, and though she demurred at
 * first--I know why, old fellow--she finally consented. It will be a
 * painful task for you, I know, old friend, but it is for _her_ sake, and
 * I must not hesitate to ask, or you to act. You are to come to lunch at
 * Hillingham to-morrow, two o'clock, so as not to arouse any suspicion in
 * Mrs. Westenra, and after lunch Lucy will take an opportunity of being
 * alone with you. I shall come in for tea, and we can go away together; I
 * am filled with anxiety, and want to consult with you alone as soon as I
 * can after you have seen her. Do not fail!
 *
 * "ARTHUR."
 *
 *
 * _Telegram, Arthur Holmwood to Seward._
 *
 * "_1 September._
 *
 * "Am summoned to see my father, who is worse. Am writing. Write me fully
 * by to-night's post to Ring. Wire me if necessary."
 *
 *
 * _Letter from Dr. Seward to Arthur Holmwood._
 *
 * "_2 September._
 *
 * "My dear old fellow,--
 *
 * "With regard to Miss Westenra's health I hasten to let you know at once
 * that in my opinion there is not any functional disturbance or any malady
 * that I know of. At the same time, I am not by any means satisfied with
 * her appearance; she is woefully different from what she was when I saw
 * her last. Of course you must bear in mind that I did not have full
 * opportunity of examination such as I should wish; our very friendship
 * makes a little difficulty which not even medical science or custom can
 * bridge over. I had better tell you exactly what happened, leaving you to
 * draw, in a measure, your own conclusions. I shall then say what I have
 * done and propose doing.
 *
 * "I found Miss Westenra in seemingly gay spirits. Her mother was present,
 * and in a few seconds I made up my mind that she was trying all she knew
 * to mislead her mother and prevent her from being anxious. I have no
 * doubt she guesses, if she does not know, what need of caution there is.
 * We lunched alone, and as we all exerted ourselves to be cheerful, we
 * got, as some kind of reward for our labours, some real cheerfulness
 * amongst us. Then Mrs. Westenra went to lie down, and Lucy was left with
 * me. We went into her boudoir, and till we got there her gaiety remained,
 * for the servants were coming and going. As soon as the door was closed,
 * however, the mask fell from her face, and she sank down into a chair
 * with a great sigh, and hid her eyes with her hand. When I saw that her
 * high spirits had failed, I at once took advantage of her reaction to
 * make a diagnosis. She said to me very sweetly:--
 *
 * "'I cannot tell you how I loathe talking about myself.' I reminded her
 * that a doctor's confidence was sacred, but that you were grievously
 * anxious about her. She caught on to my meaning at once, and settled that
 * matter in a word. 'Tell Arthur everything you choose. I do not care for
 * myself, but all for him!' So I am quite free.
 *
 * "I could easily see that she is somewhat bloodless, but I could not see
 * the usual anæmic signs, and by a chance I was actually able to test the
 * quality of her blood, for in opening a window which was stiff a cord
 * gave way, and she cut her hand slightly with broken glass. It was a
 * slight matter in itself, but it gave me an evident chance, and I secured
 * a few drops of the blood and have analysed them. The qualitative
 * analysis gives a quite normal condition, and shows, I should infer, in
 * itself a vigorous state of health. In other physical matters I was quite
 * satisfied that there is no need for anxiety; but as there must be a
 * cause somewhere, I have come to the conclusion that it must be something
 * mental. She complains of difficulty in breathing satisfactorily at
 * times, and of heavy, lethargic sleep, with dreams that frighten her, but
 * regarding which she can remember nothing. She says that as a child she
 * used to walk in her sleep, and that when in Whitby the habit came back,
 * and that once she walked out in the night and went to East Cliff, where
 * Miss Murray found her; but she assures me that of late the habit has not
 * returned. I am in doubt, and so have done the best thing I know of; I
 * have written to my old friend and master, Professor Van Helsing, of
 * Amsterdam, who knows as much about obscure diseases as any one in the
 * world. I have asked him to come over, and as you told me that all things
 * were to be at your charge, I have mentioned to him who you are and your
 * relations to Miss Westenra. This, my dear fellow, is in obedience to
 * your wishes, for I am only too proud and happy to do anything I can for
 * her. Van Helsing would, I know, do anything for me for a personal
 * reason, so, no matter on what ground he comes, we must accept his
 * wishes. He is a seemingly arbitrary man, but this is because he knows
 * what he is talking about better than any one else. He is a philosopher
 * and a metaphysician, and one of the most advanced scientists of his day;
 * and he has, I believe, an absolutely open mind. This, with an iron
 * nerve, a temper of the ice-brook, an indomitable resolution,
 * self-command, and toleration exalted from virtues to blessings, and the
 * kindliest and truest heart that beats--these form his equipment for the
 * noble work that he is doing for mankind--work both in theory and
 * practice, for his views are as wide as his all-embracing sympathy. I
 * tell you these facts that you may know why I have such confidence in
 * him. I have asked him to come at once. I shall see Miss Westenra
 * to-morrow again. She is to meet me at the Stores, so that I may not
 * alarm her mother by too early a repetition of my call.
 *
 * "Yours always,
 *
 * "JOHN SEWARD."
 *
 *
 * _Letter, Abraham Van Helsing, M. D., D. Ph., D. Lit., etc., etc., to Dr.
 * Seward._
 *
 * "_2 September._
 *
 * "My good Friend,--
 *
 * "When I have received your letter I am already coming to you. By good
 * fortune I can leave just at once, without wrong to any of those who have
 * trusted me. Were fortune other, then it were bad for those who have
 * trusted, for I come to my friend when he call me to aid those he holds
 * dear. Tell your friend that when that time you suck from my wound so
 * swiftly the poison of the gangrene from that knife that our other
 * friend, too nervous, let slip, you did more for him when he wants my
 * aids and you call for them than all his great fortune could do. But it
 * is pleasure added to do for him, your friend; it is to you that I come.
 * Have then rooms for me at the Great Eastern Hotel, so that I may be near
 * to hand, and please it so arrange that we may see the young lady not too
 * late on to-morrow, for it is likely that I may have to return here that
 * night. But if need be I shall come again in three days, and stay longer
 * if it must. Till then good-bye, my friend John.
 *
 *  "VAN HELSING."
 *
 *
 * _Letter, Dr. Seward to Hon. Arthur Holmwood._
 *
 * "_3 September._
 *
 * "My dear Art,--
 *
 * "Van Helsing has come and gone. He came on with me to Hillingham, and
 * found that, by Lucy's discretion, her mother was lunching out, so that
 * we were alone with her. Van Helsing made a very careful examination of
 * the patient. He is to report to me, and I shall advise you, for of
 * course I was not present all the time. He is, I fear, much concerned,
 * but says he must think. When I told him of our friendship and how you
 * trust to me in the matter, he said: 'You must tell him all you think.
 * Tell him what I think, if you can guess it, if you will. Nay, I am not
 * jesting. This is no jest, but life and death, perhaps more.' I asked
 * what he meant by that, for he was very serious. This was when we had
 * come back to town, and he was having a cup of tea before starting on his
 * return to Amsterdam. He would not give me any further clue. You must not
 * be angry with me, Art, because his very reticence means that all his
 * brains are working for her good. He will speak plainly enough when the
 * time comes, be sure. So I told him I would simply write an account of
 * our visit, just as if I were doing a descriptive special article for
 * _The Daily Telegraph_. He seemed not to notice, but remarked that the
 * smuts in London were not quite so bad as they used to be when he was a
 * student here. I am to get his report to-morrow if he can possibly make
 * it. In any case I am to have a letter.
 *
 * "Well, as to the visit. Lucy was more cheerful than on the day I first
 * saw her, and certainly looked better. She had lost something of the
 * ghastly look that so upset you, and her breathing was normal. She was
 * very sweet to the professor (as she always is), and tried to make him
 * feel at ease; though I could see that the poor girl was making a hard
 * struggle for it. I believe Van Helsing saw it, too, for I saw the quick
 * look under his bushy brows that I knew of old. Then he began to chat of
 * all things except ourselves and diseases and with such an infinite
 * geniality that I could see poor Lucy's pretense of animation merge into
 * reality. Then, without any seeming change, he brought the conversation
 * gently round to his visit, and suavely said:--
 *
 * "'My dear young miss, I have the so great pleasure because you are so
 * much beloved. That is much, my dear, ever were there that which I do not
 * see. They told me you were down in the spirit, and that you were of a
 * ghastly pale. To them I say: "Pouf!"' And he snapped his fingers at me
 * and went on: 'But you and I shall show them how wrong they are. How can
 * he'--and he pointed at me with the same look and gesture as that with
 * which once he pointed me out to his class, on, or rather after, a
 * particular occasion which he never fails to remind me of--'know anything
 * of a young ladies? He has his madams to play with, and to bring them
 * back to happiness, and to those that love them. It is much to do, and,
 * oh, but there are rewards, in that we can bestow such happiness. But the
 * young ladies! He has no wife nor daughter, and the young do not tell
 * themselves to the young, but to the old, like me, who have known so many
 * sorrows and the causes of them. So, my dear, we will send him away to
 * smoke the cigarette in the garden, whiles you and I have little talk all
 * to ourselves.' I took the hint, and strolled about, and presently the
 * professor came to the window and called me in. He looked grave, but
 * said: 'I have made careful examination, but there is no functional
 * cause. With you I agree that there has been much blood lost; it has
 * been, but is not. But the conditions of her are in no way anæmic. I have
 * asked her to send me her maid, that I may ask just one or two question,
 * that so I may not chance to miss nothing. I know well what she will say.
 * And yet there is cause; there is always cause for everything. I must go
 * back home and think. You must send to me the telegram every day; and if
 * there be cause I shall come again. The disease--for not to be all well
 * is a disease--interest me, and the sweet young dear, she interest me
 * too. She charm me, and for her, if not for you or disease, I come.'
 *
 * "As I tell you, he would not say a word more, even when we were alone.
 * And so now, Art, you know all I know. I shall keep stern watch. I trust
 * your poor father is rallying. It must be a terrible thing to you, my
 * dear old fellow, to be placed in such a position between two people who
 * are both so dear to you. I know your idea of duty to your father, and
 * you are right to stick to it; but, if need be, I shall send you word to
 * come at once to Lucy; so do not be over-anxious unless you hear from
 * me."
 *
 *
 * _Dr. Seward's Diary._
 *
 * _4 September._--Zoöphagous patient still keeps up our interest in him.
 * He had only one outburst and that was yesterday at an unusual time. Just
 * before the stroke of noon he began to grow restless. The attendant knew
 * the symptoms, and at once summoned aid. Fortunately the men came at a
 * run, and were just in time, for at the stroke of noon he became so
 * violent that it took all their strength to hold him. In about five
 * minutes, however, he began to get more and more quiet, and finally sank
 * into a sort of melancholy, in which state he has remained up to now. The
 * attendant tells me that his screams whilst in the paroxysm were really
 * appalling; I found my hands full when I got in, attending to some of the
 * other patients who were frightened by him. Indeed, I can quite
 * understand the effect, for the sounds disturbed even me, though I was
 * some distance away. It is now after the dinner-hour of the asylum, and
 * as yet my patient sits in a corner brooding, with a dull, sullen,
 * woe-begone look in his face, which seems rather to indicate than to show
 * something directly. I cannot quite understand it.
 *
 *        *       *       *       *       *
 *
 * _Later._--Another change in my patient. At five o'clock I looked in on
 * him, and found him seemingly as happy and contented as he used to be. He
 * was catching flies and eating them, and was keeping note of his capture
 * by making nail-marks on the edge of the door between the ridges of
 * padding. When he saw me, he came over and apologised for his bad
 * conduct, and asked me in a very humble, cringing way to be led back to
 * his own room and to have his note-book again. I thought it well to
 * humour him: so he is back in his room with the window open. He has the
 * sugar of his tea spread out on the window-sill, and is reaping quite a
 * harvest of flies. He is not now eating them, but putting them into a
 * box, as of old, and is already examining the corners of his room to find
 * a spider. I tried to get him to talk about the past few days, for any
 * clue to his thoughts would be of immense help to me; but he would not
 * rise. For a moment or two he looked very sad, and said in a sort of
 * far-away voice, as though saying it rather to himself than to me:--
 *
 * "All over! all over! He has deserted me. No hope for me now unless I do
 * it for myself!" Then suddenly turning to me in a resolute way, he said:
 * "Doctor, won't you be very good to me and let me have a little more
 * sugar? I think it would be good for me."
 *
 * "And the flies?" I said.
 *
 * "Yes! The flies like it, too, and I like the flies; therefore I like
 * it." And there are people who know so little as to think that madmen do
 * not argue. I procured him a double supply, and left him as happy a man
 * as, I suppose, any in the world. I wish I could fathom his mind.
 *
 *        *       *       *       *       *
 *
 * _Midnight._--Another change in him. I had been to see Miss Westenra,
 * whom I found much better, and had just returned, and was standing at our
 * own gate looking at the sunset, when once more I heard him yelling. As
 * his room is on this side of the house, I could hear it better than in
 * the morning. It was a shock to me to turn from the wonderful smoky
 * beauty of a sunset over London, with its lurid lights and inky shadows
 * and all the marvellous tints that come on foul clouds even as on foul
 * water, and to realise all the grim sternness of my own cold stone
 * building, with its wealth of breathing misery, and my own desolate heart
 * to endure it all. I reached him just as the sun was going down, and from
 * his window saw the red disc sink. As it sank he became less and less
 * frenzied; and just as it dipped he slid from the hands that held him, an
 * inert mass, on the floor. It is wonderful, however, what intellectual
 * recuperative power lunatics have, for within a few minutes he stood up
 * quite calmly and looked around him. I signalled to the attendants not to
 * hold him, for I was anxious to see what he would do. He went straight
 * over to the window and brushed out the crumbs of sugar; then he took his
 * fly-box, and emptied it outside, and threw away the box; then he shut
 * the window, and crossing over, sat down on his bed. All this surprised
 * me, so I asked him: "Are you not going to keep flies any more?"
 *
 * "No," said he; "I am sick of all that rubbish!" He certainly is a
 * wonderfully interesting study. I wish I could get some glimpse of his
 * mind or of the cause of his sudden passion. Stop; there may be a clue
 * after all, if we can find why to-day his paroxysms came on at high noon
 * and at sunset. Can it be that there is a malign influence of the sun at
 * periods which affects certain natures--as at times the moon does others?
 * We shall see.
 *
 *
 * _Telegram, Seward, London, to Van Helsing, Amsterdam._
 *
 * "_4 September._--Patient still better to-day."
 *
 *
 * _Telegram, Seward, London, to Van Helsing, Amsterdam._
 *
 * "_5 September._--Patient greatly improved. Good appetite; sleeps
 * naturally; good spirits; colour coming back."
 *
 *
 * _Telegram, Seward, London, to Van Helsing, Amsterdam._
 *
 * "_6 September._--Terrible change for the worse. Come at once; do not
 * lose an hour. I hold over telegram to Holmwood till have seen you."
 */
/*                                                                             *
 **                                                                           **
 ***                                                                         ***
 ****                                                                       ****
 *****                                                                     *****
 ******                                                                   ******
 *******                                                                 *******
 ******                                                                   ******
 *****                                                                     *****
 ****                                                                       ****
 ***                                                                         ***
 **                                                                           **
 *                                                                             */
/**
 * \page chapter_X CHAPTER X: Mina Murray's Journal
 * _Letter, Dr. Seward to Hon. Arthur Holmwood._
 *
 * "_6 September._
 *
 * "My dear Art,--
 *
 * "My news to-day is not so good. Lucy this morning had gone back a bit.
 * There is, however, one good thing which has arisen from it; Mrs.
 * Westenra was naturally anxious concerning Lucy, and has consulted me
 * professionally about her. I took advantage of the opportunity, and told
 * her that my old master, Van Helsing, the great specialist, was coming to
 * stay with me, and that I would put her in his charge conjointly with
 * myself; so now we can come and go without alarming her unduly, for a
 * shock to her would mean sudden death, and this, in Lucy's weak
 * condition, might be disastrous to her. We are hedged in with
 * difficulties, all of us, my poor old fellow; but, please God, we shall
 * come through them all right. If any need I shall write, so that, if you
 * do not hear from me, take it for granted that I am simply waiting for
 * news. In haste
 *
 * Yours ever,
 *
 * "JOHN SEWARD."
 *
 *
 * _Dr. Seward's Diary._
 *
 * _7 September._--The first thing Van Helsing said to me when we met at
 * Liverpool Street was:--
 *
 * "Have you said anything to our young friend the lover of her?"
 *
 * "No," I said. "I waited till I had seen you, as I said in my telegram. I
 * wrote him a letter simply telling him that you were coming, as Miss
 * Westenra was not so well, and that I should let him know if need be."
 *
 * "Right, my friend," he said, "quite right! Better he not know as yet;
 * perhaps he shall never know. I pray so; but if it be needed, then he
 * shall know all. And, my good friend John, let me caution you. You deal
 * with the madmen. All men are mad in some way or the other; and inasmuch
 * as you deal discreetly with your madmen, so deal with God's madmen,
 * too--the rest of the world. You tell not your madmen what you do nor why
 * you do it; you tell them not what you think. So you shall keep knowledge
 * in its place, where it may rest--where it may gather its kind around it
 * and breed. You and I shall keep as yet what we know here, and here." He
 * touched me on the heart and on the forehead, and then touched himself
 * the same way. "I have for myself thoughts at the present. Later I shall
 * unfold to you."
 *
 * "Why not now?" I asked. "It may do some good; we may arrive at some
 * decision." He stopped and looked at me, and said:--
 *
 * "My friend John, when the corn is grown, even before it has
 * ripened--while the milk of its mother-earth is in him, and the sunshine
 * has not yet begun to paint him with his gold, the husbandman he pull the
 * ear and rub him between his rough hands, and blow away the green chaff,
 * and say to you: 'Look! he's good corn; he will make good crop when the
 * time comes.'" I did not see the application, and told him so. For reply
 * he reached over and took my ear in his hand and pulled it playfully, as
 * he used long ago to do at lectures, and said: "The good husbandman tell
 * you so then because he knows, but not till then. But you do not find the
 * good husbandman dig up his planted corn to see if he grow; that is for
 * the children who play at husbandry, and not for those who take it as of
 * the work of their life. See you now, friend John? I have sown my corn,
 * and Nature has her work to do in making it sprout; if he sprout at all,
 * there's some promise; and I wait till the ear begins to swell." He broke
 * off, for he evidently saw that I understood. Then he went on, and very
 * gravely:--
 *
 * "You were always a careful student, and your case-book was ever more
 * full than the rest. You were only student then; now you are master, and
 * I trust that good habit have not fail. Remember, my friend, that
 * knowledge is stronger than memory, and we should not trust the weaker.
 * Even if you have not kept the good practise, let me tell you that this
 * case of our dear miss is one that may be--mind, I say _may be_--of such
 * interest to us and others that all the rest may not make him kick the
 * beam, as your peoples say. Take then good note of it. Nothing is too
 * small. I counsel you, put down in record even your doubts and surmises.
 * Hereafter it may be of interest to you to see how true you guess. We
 * learn from failure, not from success!"
 *
 * When I described Lucy's symptoms--the same as before, but infinitely
 * more marked--he looked very grave, but said nothing. He took with him a
 * bag in which were many instruments and drugs, "the ghastly paraphernalia
 * of our beneficial trade," as he once called, in one of his lectures, the
 * equipment of a professor of the healing craft. When we were shown in,
 * Mrs. Westenra met us. She was alarmed, but not nearly so much as I
 * expected to find her. Nature in one of her beneficent moods has ordained
 * that even death has some antidote to its own terrors. Here, in a case
 * where any shock may prove fatal, matters are so ordered that, from some
 * cause or other, the things not personal--even the terrible change in her
 * daughter to whom she is so attached--do not seem to reach her. It is
 * something like the way Dame Nature gathers round a foreign body an
 * envelope of some insensitive tissue which can protect from evil that
 * which it would otherwise harm by contact. If this be an ordered
 * selfishness, then we should pause before we condemn any one for the vice
 * of egoism, for there may be deeper root for its causes than we have
 * knowledge of.
 *
 * I used my knowledge of this phase of spiritual pathology, and laid down
 * a rule that she should not be present with Lucy or think of her illness
 * more than was absolutely required. She assented readily, so readily that
 * I saw again the hand of Nature fighting for life. Van Helsing and I were
 * shown up to Lucy's room. If I was shocked when I saw her yesterday, I
 * was horrified when I saw her to-day. She was ghastly, chalkily pale; the
 * red seemed to have gone even from her lips and gums, and the bones of
 * her face stood out prominently; her breathing was painful to see or
 * hear. Van Helsing's face grew set as marble, and his eyebrows converged
 * till they almost touched over his nose. Lucy lay motionless, and did not
 * seem to have strength to speak, so for a while we were all silent. Then
 * Van Helsing beckoned to me, and we went gently out of the room. The
 * instant we had closed the door he stepped quickly along the passage to
 * the next door, which was open. Then he pulled me quickly in with him and
 * closed the door. "My God!" he said; "this is dreadful. There is no time
 * to be lost. She will die for sheer want of blood to keep the heart's
 * action as it should be. There must be transfusion of blood at once. Is
 * it you or me?"
 *
 * "I am younger and stronger, Professor. It must be me."
 *
 * "Then get ready at once. I will bring up my bag. I am prepared."
 *
 * I went downstairs with him, and as we were going there was a knock at
 * the hall-door. When we reached the hall the maid had just opened the
 * door, and Arthur was stepping quickly in. He rushed up to me, saying in
 * an eager whisper:--
 *
 * "Jack, I was so anxious. I read between the lines of your letter, and
 * have been in an agony. The dad was better, so I ran down here to see for
 * myself. Is not that gentleman Dr. Van Helsing? I am so thankful to you,
 * sir, for coming." When first the Professor's eye had lit upon him he had
 * been angry at his interruption at such a time; but now, as he took in
 * his stalwart proportions and recognised the strong young manhood which
 * seemed to emanate from him, his eyes gleamed. Without a pause he said to
 * him gravely as he held out his hand:--
 *
 * "Sir, you have come in time. You are the lover of our dear miss. She is
 * bad, very, very bad. Nay, my child, do not go like that." For he
 * suddenly grew pale and sat down in a chair almost fainting. "You are to
 * help her. You can do more than any that live, and your courage is your
 * best help."
 *
 * "What can I do?" asked Arthur hoarsely. "Tell me, and I shall do it. My
 * life is hers, and I would give the last drop of blood in my body for
 * her." The Professor has a strongly humorous side, and I could from old
 * knowledge detect a trace of its origin in his answer:--
 *
 * "My young sir, I do not ask so much as that--not the last!"
 *
 * "What shall I do?" There was fire in his eyes, and his open nostril
 * quivered with intent. Van Helsing slapped him on the shoulder. "Come!"
 * he said. "You are a man, and it is a man we want. You are better than
 * me, better than my friend John." Arthur looked bewildered, and the
 * Professor went on by explaining in a kindly way:--
 *
 * "Young miss is bad, very bad. She wants blood, and blood she must have
 * or die. My friend John and I have consulted; and we are about to perform
 * what we call transfusion of blood--to transfer from full veins of one to
 * the empty veins which pine for him. John was to give his blood, as he is
 * the more young and strong than me"--here Arthur took my hand and wrung
 * it hard in silence--"but, now you are here, you are more good than us,
 * old or young, who toil much in the world of thought. Our nerves are not
 * so calm and our blood not so bright than yours!" Arthur turned to him
 * and said:--
 *
 * "If you only knew how gladly I would die for her you would
 * understand----"
 *
 * He stopped, with a sort of choke in his voice.
 *
 * "Good boy!" said Van Helsing. "In the not-so-far-off you will be happy
 * that you have done all for her you love. Come now and be silent. You
 * shall kiss her once before it is done, but then you must go; and you
 * must leave at my sign. Say no word to Madame; you know how it is with
 * her! There must be no shock; any knowledge of this would be one. Come!"
 *
 * We all went up to Lucy's room. Arthur by direction remained outside.
 * Lucy turned her head and looked at us, but said nothing. She was not
 * asleep, but she was simply too weak to make the effort. Her eyes spoke
 * to us; that was all. Van Helsing took some things from his bag and laid
 * them on a little table out of sight. Then he mixed a narcotic, and
 * coming over to the bed, said cheerily:--
 *
 * "Now, little miss, here is your medicine. Drink it off, like a good
 * child. See, I lift you so that to swallow is easy. Yes." She had made
 * the effort with success.
 *
 * It astonished me how long the drug took to act. This, in fact, marked
 * the extent of her weakness. The time seemed endless until sleep began to
 * flicker in her eyelids. At last, however, the narcotic began to manifest
 * its potency; and she fell into a deep sleep. When the Professor was
 * satisfied he called Arthur into the room, and bade him strip off his
 * coat. Then he added: "You may take that one little kiss whiles I bring
 * over the table. Friend John, help to me!" So neither of us looked whilst
 * he bent over her.
 *
 * Van Helsing turning to me, said:
 *
 * "He is so young and strong and of blood so pure that we need not
 * defibrinate it."
 *
 * Then with swiftness, but with absolute method, Van Helsing performed the
 * operation. As the transfusion went on something like life seemed to come
 * back to poor Lucy's cheeks, and through Arthur's growing pallor the joy
 * of his face seemed absolutely to shine. After a bit I began to grow
 * anxious, for the loss of blood was telling on Arthur, strong man as he
 * was. It gave me an idea of what a terrible strain Lucy's system must
 * have undergone that what weakened Arthur only partially restored her.
 * But the Professor's face was set, and he stood watch in hand and with
 * his eyes fixed now on the patient and now on Arthur. I could hear my own
 * heart beat. Presently he said in a soft voice: "Do not stir an instant.
 * It is enough. You attend him; I will look to her." When all was over I
 * could see how much Arthur was weakened. I dressed the wound and took his
 * arm to bring him away, when Van Helsing spoke without turning round--the
 * man seems to have eyes in the back of his head:--
 *
 * "The brave lover, I think, deserve another kiss, which he shall have
 * presently." And as he had now finished his operation, he adjusted the
 * pillow to the patient's head. As he did so the narrow black velvet band
 * which she seems always to wear round her throat, buckled with an old
 * diamond buckle which her lover had given her, was dragged a little up,
 * and showed a red mark on her throat. Arthur did not notice it, but I
 * could hear the deep hiss of indrawn breath which is one of Van Helsing's
 * ways of betraying emotion. He said nothing at the moment, but turned to
 * me, saying: "Now take down our brave young lover, give him of the port
 * wine, and let him lie down a while. He must then go home and rest, sleep
 * much and eat much, that he may be recruited of what he has so given to
 * his love. He must not stay here. Hold! a moment. I may take it, sir,
 * that you are anxious of result. Then bring it with you that in all ways
 * the operation is successful. You have saved her life this time, and you
 * can go home and rest easy in mind that all that can be is. I shall tell
 * her all when she is well; she shall love you none the less for what you
 * have done. Good-bye."
 *
 * When Arthur had gone I went back to the room. Lucy was sleeping gently,
 * but her breathing was stronger; I could see the counterpane move as her
 * breast heaved. By the bedside sat Van Helsing, looking at her intently.
 * The velvet band again covered the red mark. I asked the Professor in a
 * whisper:--
 *
 * "What do you make of that mark on her throat?"
 *
 * "What do you make of it?"
 *
 * "I have not examined it yet," I answered, and then and there proceeded
 * to loose the band. Just over the external jugular vein there were two
 * punctures, not large, but not wholesome-looking. There was no sign of
 * disease, but the edges were white and worn-looking, as if by some
 * trituration. It at once occurred to me that this wound, or whatever it
 * was, might be the means of that manifest loss of blood; but I abandoned
 * the idea as soon as formed, for such a thing could not be. The whole bed
 * would have been drenched to a scarlet with the blood which the girl must
 * have lost to leave such a pallor as she had before the transfusion.
 *
 * "Well?" said Van Helsing.
 *
 * "Well," said I, "I can make nothing of it." The Professor stood up. "I
 * must go back to Amsterdam to-night," he said. "There are books and
 * things there which I want. You must remain here all the night, and you
 * must not let your sight pass from her."
 *
 * "Shall I have a nurse?" I asked.
 *
 * "We are the best nurses, you and I. You keep watch all night; see that
 * she is well fed, and that nothing disturbs her. You must not sleep all
 * the night. Later on we can sleep, you and I. I shall be back as soon as
 * possible. And then we may begin."
 *
 * "May begin?" I said. "What on earth do you mean?"
 *
 * "We shall see!" he answered, as he hurried out. He came back a moment
 * later and put his head inside the door and said with warning finger held
 * up:--
 *
 * "Remember, she is your charge. If you leave her, and harm befall, you
 * shall not sleep easy hereafter!"
 *
 *
 * _Dr. Seward's Diary--continued._
 *
 * _8 September._--I sat up all night with Lucy. The opiate worked itself
 * off towards dusk, and she waked naturally; she looked a different being
 * from what she had been before the operation. Her spirits even were good,
 * and she was full of a happy vivacity, but I could see evidences of the
 * absolute prostration which she had undergone. When I told Mrs. Westenra
 * that Dr. Van Helsing had directed that I should sit up with her she
 * almost pooh-poohed the idea, pointing out her daughter's renewed
 * strength and excellent spirits. I was firm, however, and made
 * preparations for my long vigil. When her maid had prepared her for the
 * night I came in, having in the meantime had supper, and took a seat by
 * the bedside. She did not in any way make objection, but looked at me
 * gratefully whenever I caught her eye. After a long spell she seemed
 * sinking off to sleep, but with an effort seemed to pull herself together
 * and shook it off. This was repeated several times, with greater effort
 * and with shorter pauses as the time moved on. It was apparent that she
 * did not want to sleep, so I tackled the subject at once:--
 *
 * "You do not want to go to sleep?"
 *
 * "No; I am afraid."
 *
 * "Afraid to go to sleep! Why so? It is the boon we all crave for."
 *
 * "Ah, not if you were like me--if sleep was to you a presage of horror!"
 *
 * "A presage of horror! What on earth do you mean?"
 *
 * "I don't know; oh, I don't know. And that is what is so terrible. All
 * this weakness comes to me in sleep; until I dread the very thought."
 *
 * "But, my dear girl, you may sleep to-night. I am here watching you, and
 * I can promise that nothing will happen."
 *
 * "Ah, I can trust you!" I seized the opportunity, and said: "I promise
 * you that if I see any evidence of bad dreams I will wake you at once."
 *
 * "You will? Oh, will you really? How good you are to me. Then I will
 * sleep!" And almost at the word she gave a deep sigh of relief, and sank
 * back, asleep.
 *
 * All night long I watched by her. She never stirred, but slept on and on
 * in a deep, tranquil, life-giving, health-giving sleep. Her lips were
 * slightly parted, and her breast rose and fell with the regularity of a
 * pendulum. There was a smile on her face, and it was evident that no bad
 * dreams had come to disturb her peace of mind.
 *
 * In the early morning her maid came, and I left her in her care and took
 * myself back home, for I was anxious about many things. I sent a short
 * wire to Van Helsing and to Arthur, telling them of the excellent result
 * of the operation. My own work, with its manifold arrears, took me all
 * day to clear off; it was dark when I was able to inquire about my
 * zoöphagous patient. The report was good; he had been quite quiet for the
 * past day and night. A telegram came from Van Helsing at Amsterdam whilst
 * I was at dinner, suggesting that I should be at Hillingham to-night, as
 * it might be well to be at hand, and stating that he was leaving by the
 * night mail and would join me early in the morning.
 *
 *        *       *       *       *       *
 *
 * _9 September_.--I was pretty tired and worn out when I got to
 * Hillingham. For two nights I had hardly had a wink of sleep, and my
 * brain was beginning to feel that numbness which marks cerebral
 * exhaustion. Lucy was up and in cheerful spirits. When she shook hands
 * with me she looked sharply in my face and said:--
 *
 * "No sitting up to-night for you. You are worn out. I am quite well
 * again; indeed, I am; and if there is to be any sitting up, it is I who
 * will sit up with you." I would not argue the point, but went and had my
 * supper. Lucy came with me, and, enlivened by her charming presence, I
 * made an excellent meal, and had a couple of glasses of the more than
 * excellent port. Then Lucy took me upstairs, and showed me a room next
 * her own, where a cozy fire was burning. "Now," she said, "you must stay
 * here. I shall leave this door open and my door too. You can lie on the
 * sofa for I know that nothing would induce any of you doctors to go to
 * bed whilst there is a patient above the horizon. If I want anything I
 * shall call out, and you can come to me at once." I could not but
 * acquiesce, for I was "dog-tired," and could not have sat up had I tried.
 * So, on her renewing her promise to call me if she should want anything,
 * I lay on the sofa, and forgot all about everything.
 *
 *
 * _Lucy Westenra's Diary._
 *
 * _9 September._--I feel so happy to-night. I have been so miserably weak,
 * that to be able to think and move about is like feeling sunshine after
 * a long spell of east wind out of a steel sky. Somehow Arthur feels very,
 * very close to me. I seem to feel his presence warm about me. I suppose
 * it is that sickness and weakness are selfish things and turn our inner
 * eyes and sympathy on ourselves, whilst health and strength give Love
 * rein, and in thought and feeling he can wander where he wills. I know
 * where my thoughts are. If Arthur only knew! My dear, my dear, your ears
 * must tingle as you sleep, as mine do waking. Oh, the blissful rest of
 * last night! How I slept, with that dear, good Dr. Seward watching me.
 * And to-night I shall not fear to sleep, since he is close at hand and
 * within call. Thank everybody for being so good to me! Thank God!
 * Good-night, Arthur.
 *
 *
 * _Dr. Seward's Diary._
 *
 * _10 September._--I was conscious of the Professor's hand on my head, and
 * started awake all in a second. That is one of the things that we learn
 * in an asylum, at any rate.
 *
 * "And how is our patient?"
 *
 * "Well, when I left her, or rather when she left me," I answered.
 *
 * "Come, let us see," he said. And together we went into the room.
 *
 * The blind was down, and I went over to raise it gently, whilst Van
 * Helsing stepped, with his soft, cat-like tread, over to the bed.
 *
 * As I raised the blind, and the morning sunlight flooded the room, I
 * heard the Professor's low hiss of inspiration, and knowing its rarity, a
 * deadly fear shot through my heart. As I passed over he moved back, and
 * his exclamation of horror, "Gott in Himmel!" needed no enforcement from
 * his agonised face. He raised his hand and pointed to the bed, and his
 * iron face was drawn and ashen white. I felt my knees begin to tremble.
 *
 * There on the bed, seemingly in a swoon, lay poor Lucy, more horribly
 * white and wan-looking than ever. Even the lips were white, and the gums
 * seemed to have shrunken back from the teeth, as we sometimes see in a
 * corpse after a prolonged illness. Van Helsing raised his foot to stamp
 * in anger, but the instinct of his life and all the long years of habit
 * stood to him, and he put it down again softly. "Quick!" he said. "Bring
 * the brandy." I flew to the dining-room, and returned with the decanter.
 * He wetted the poor white lips with it, and together we rubbed palm and
 * wrist and heart. He felt her heart, and after a few moments of agonising
 * suspense said:--
 *
 * "It is not too late. It beats, though but feebly. All our work is
 * undone; we must begin again. There is no young Arthur here now; I have
 * to call on you yourself this time, friend John." As he spoke, he was
 * dipping into his bag and producing the instruments for transfusion; I
 * had taken off my coat and rolled up my shirt-sleeve. There was no
 * possibility of an opiate just at present, and no need of one; and so,
 * without a moment's delay, we began the operation. After a time--it did
 * not seem a short time either, for the draining away of one's blood, no
 * matter how willingly it be given, is a terrible feeling--Van Helsing
 * held up a warning finger. "Do not stir," he said, "but I fear that with
 * growing strength she may wake; and that would make danger, oh, so much
 * danger. But I shall precaution take. I shall give hypodermic injection
 * of morphia." He proceeded then, swiftly and deftly, to carry out his
 * intent. The effect on Lucy was not bad, for the faint seemed to merge
 * subtly into the narcotic sleep. It was with a feeling of personal pride
 * that I could see a faint tinge of colour steal back into the pallid
 * cheeks and lips. No man knows, till he experiences it, what it is to
 * feel his own life-blood drawn away into the veins of the woman he loves.
 *
 * The Professor watched me critically. "That will do," he said. "Already?"
 * I remonstrated. "You took a great deal more from Art." To which he
 * smiled a sad sort of smile as he replied:--
 *
 * "He is her lover, her _fiancé_. You have work, much work, to do for her
 * and for others; and the present will suffice."
 *
 * When we stopped the operation, he attended to Lucy, whilst I applied
 * digital pressure to my own incision. I laid down, whilst I waited his
 * leisure to attend to me, for I felt faint and a little sick. By-and-by
 * he bound up my wound, and sent me downstairs to get a glass of wine for
 * myself. As I was leaving the room, he came after me, and half
 * whispered:--
 *
 * "Mind, nothing must be said of this. If our young lover should turn up
 * unexpected, as before, no word to him. It would at once frighten him and
 * enjealous him, too. There must be none. So!"
 *
 * When I came back he looked at me carefully, and then said:--
 *
 * "You are not much the worse. Go into the room, and lie on your sofa, and
 * rest awhile; then have much breakfast, and come here to me."
 *
 * I followed out his orders, for I knew how right and wise they were. I
 * had done my part, and now my next duty was to keep up my strength. I
 * felt very weak, and in the weakness lost something of the amazement at
 * what had occurred. I fell asleep on the sofa, however, wondering over
 * and over again how Lucy had made such a retrograde movement, and how
 * she could have been drained of so much blood with no sign anywhere to
 * show for it. I think I must have continued my wonder in my dreams, for,
 * sleeping and waking, my thoughts always came back to the little
 * punctures in her throat and the ragged, exhausted appearance of their
 * edges--tiny though they were.
 *
 * Lucy slept well into the day, and when she woke she was fairly well and
 * strong, though not nearly so much so as the day before. When Van Helsing
 * had seen her, he went out for a walk, leaving me in charge, with strict
 * injunctions that I was not to leave her for a moment. I could hear his
 * voice in the hall, asking the way to the nearest telegraph office.
 *
 * Lucy chatted with me freely, and seemed quite unconscious that anything
 * had happened. I tried to keep her amused and interested. When her mother
 * came up to see her, she did not seem to notice any change whatever, but
 * said to me gratefully:--
 *
 * "We owe you so much, Dr. Seward, for all you have done, but you really
 * must now take care not to overwork yourself. You are looking pale
 * yourself. You want a wife to nurse and look after you a bit; that you
 * do!" As she spoke, Lucy turned crimson, though it was only momentarily,
 * for her poor wasted veins could not stand for long such an unwonted
 * drain to the head. The reaction came in excessive pallor as she turned
 * imploring eyes on me. I smiled and nodded, and laid my finger on my
 * lips; with a sigh, she sank back amid her pillows.
 *
 * Van Helsing returned in a couple of hours, and presently said to me:
 * "Now you go home, and eat much and drink enough. Make yourself strong. I
 * stay here to-night, and I shall sit up with little miss myself. You and
 * I must watch the case, and we must have none other to know. I have grave
 * reasons. No, do not ask them; think what you will. Do not fear to think
 * even the most not-probable. Good-night."
 *
 * In the hall two of the maids came to me, and asked if they or either of
 * them might not sit up with Miss Lucy. They implored me to let them; and
 * when I said it was Dr. Van Helsing's wish that either he or I should sit
 * up, they asked me quite piteously to intercede with the "foreign
 * gentleman." I was much touched by their kindness. Perhaps it is because
 * I am weak at present, and perhaps because it was on Lucy's account, that
 * their devotion was manifested; for over and over again have I seen
 * similar instances of woman's kindness. I got back here in time for a
 * late dinner; went my rounds--all well; and set this down whilst waiting
 * for sleep. It is coming.
 *
 *        *       *       *       *       *
 *
 * _11 September._--This afternoon I went over to Hillingham. Found Van
 * Helsing in excellent spirits, and Lucy much better. Shortly after I had
 * arrived, a big parcel from abroad came for the Professor. He opened it
 * with much impressment--assumed, of course--and showed a great bundle of
 * white flowers.
 *
 * "These are for you, Miss Lucy," he said.
 *
 * "For me? Oh, Dr. Van Helsing!"
 *
 * "Yes, my dear, but not for you to play with. These are medicines." Here
 * Lucy made a wry face. "Nay, but they are not to take in a decoction or
 * in nauseous form, so you need not snub that so charming nose, or I shall
 * point out to my friend Arthur what woes he may have to endure in seeing
 * so much beauty that he so loves so much distort. Aha, my pretty miss,
 * that bring the so nice nose all straight again. This is medicinal, but
 * you do not know how. I put him in your window, I make pretty wreath, and
 * hang him round your neck, so that you sleep well. Oh yes! they, like the
 * lotus flower, make your trouble forgotten. It smell so like the waters
 * of Lethe, and of that fountain of youth that the Conquistadores sought
 * for in the Floridas, and find him all too late."
 *
 * Whilst he was speaking, Lucy had been examining the flowers and smelling
 * them. Now she threw them down, saying, with half-laughter, and
 * half-disgust:--
 *
 * "Oh, Professor, I believe you are only putting up a joke on me. Why,
 * these flowers are only common garlic."
 *
 * To my surprise, Van Helsing rose up and said with all his sternness, his
 * iron jaw set and his bushy eyebrows meeting:--
 *
 * "No trifling with me! I never jest! There is grim purpose in all I do;
 * and I warn you that you do not thwart me. Take care, for the sake of
 * others if not for your own." Then seeing poor Lucy scared, as she might
 * well be, he went on more gently: "Oh, little miss, my dear, do not fear
 * me. I only do for your good; but there is much virtue to you in those so
 * common flowers. See, I place them myself in your room. I make myself the
 * wreath that you are to wear. But hush! no telling to others that make so
 * inquisitive questions. We must obey, and silence is a part of obedience;
 * and obedience is to bring you strong and well into loving arms that wait
 * for you. Now sit still awhile. Come with me, friend John, and you shall
 * help me deck the room with my garlic, which is all the way from Haarlem,
 * where my friend Vanderpool raise herb in his glass-houses all the year.
 * I had to telegraph yesterday, or they would not have been here."
 *
 * We went into the room, taking the flowers with us. The Professor's
 * actions were certainly odd and not to be found in any pharmacopoeia
 * that I ever heard of. First he fastened up the windows and latched them
 * securely; next, taking a handful of the flowers, he rubbed them all over
 * the sashes, as though to ensure that every whiff of air that might get
 * in would be laden with the garlic smell. Then with the wisp he rubbed
 * all over the jamb of the door, above, below, and at each side, and round
 * the fireplace in the same way. It all seemed grotesque to me, and
 * presently I said:--
 *
 * "Well, Professor, I know you always have a reason for what you do, but
 * this certainly puzzles me. It is well we have no sceptic here, or he
 * would say that you were working some spell to keep out an evil spirit."
 *
 * "Perhaps I am!" he answered quietly as he began to make the wreath which
 * Lucy was to wear round her neck.
 *
 * We then waited whilst Lucy made her toilet for the night, and when she
 * was in bed he came and himself fixed the wreath of garlic round her
 * neck. The last words he said to her were:--
 *
 * "Take care you do not disturb it; and even if the room feel close, do
 * not to-night open the window or the door."
 *
 * "I promise," said Lucy, "and thank you both a thousand times for all
 * your kindness to me! Oh, what have I done to be blessed with such
 * friends?"
 *
 * As we left the house in my fly, which was waiting, Van Helsing said:--
 *
 * "To-night I can sleep in peace, and sleep I want--two nights of travel,
 * much reading in the day between, and much anxiety on the day to follow,
 * and a night to sit up, without to wink. To-morrow in the morning early
 * you call for me, and we come together to see our pretty miss, so much
 * more strong for my 'spell' which I have work. Ho! ho!"
 *
 * He seemed so confident that I, remembering my own confidence two nights
 * before and with the baneful result, felt awe and vague terror. It must
 * have been my weakness that made me hesitate to tell it to my friend, but
 * I felt it all the more, like unshed tears.
 */
/*                                                                             *
 **                                                                           **
 ***                                                                         ***
 ****                                                                       ****
 *****                                                                     *****
 ******                                                                   ******
 *******                                                                 *******
 ******                                                                   ******
 *****                                                                     *****
 ****                                                                       ****
 ***                                                                         ***
 **                                                                           **
 *                                                                             */
/**
 * \page chapter_XI CHAPTER XI: Lucy Westenra's Diary
 * _Lucy Westenra's Diary._
 *
 *
 * _12 September._--How good they all are to me. I quite love that dear Dr.
 * Van Helsing. I wonder why he was so anxious about these flowers. He
 * positively frightened me, he was so fierce. And yet he must have been
 * right, for I feel comfort from them already. Somehow, I do not dread
 * being alone to-night, and I can go to sleep without fear. I shall not
 * mind any flapping outside the window. Oh, the terrible struggle that I
 * have had against sleep so often of late; the pain of the sleeplessness,
 * or the pain of the fear of sleep, with such unknown horrors as it has
 * for me! How blessed are some people, whose lives have no fears, no
 * dreads; to whom sleep is a blessing that comes nightly, and brings
 * nothing but sweet dreams. Well, here I am to-night, hoping for sleep,
 * and lying like Ophelia in the play, with "virgin crants and maiden
 * strewments." I never liked garlic before, but to-night it is delightful!
 * There is peace in its smell; I feel sleep coming already. Good-night,
 * everybody.
 *
 *
 * _Dr. Seward's Diary._
 *
 * _13 September._--Called at the Berkeley and found Van Helsing, as usual,
 * up to time. The carriage ordered from the hotel was waiting. The
 * Professor took his bag, which he always brings with him now.
 *
 * Let all be put down exactly. Van Helsing and I arrived at Hillingham at
 * eight o'clock. It was a lovely morning; the bright sunshine and all the
 * fresh feeling of early autumn seemed like the completion of nature's
 * annual work. The leaves were turning to all kinds of beautiful colours,
 * but had not yet begun to drop from the trees. When we entered we met
 * Mrs. Westenra coming out of the morning room. She is always an early
 * riser. She greeted us warmly and said:--
 *
 * "You will be glad to know that Lucy is better. The dear child is still
 * asleep. I looked into her room and saw her, but did not go in, lest I
 * should disturb her." The Professor smiled, and looked quite jubilant. He
 * rubbed his hands together, and said:--
 *
 * "Aha! I thought I had diagnosed the case. My treatment is working," to
 * which she answered:--
 *
 * "You must not take all the credit to yourself, doctor. Lucy's state this
 * morning is due in part to me."
 *
 * "How you do mean, ma'am?" asked the Professor.
 *
 * "Well, I was anxious about the dear child in the night, and went into
 * her room. She was sleeping soundly--so soundly that even my coming did
 * not wake her. But the room was awfully stuffy. There were a lot of those
 * horrible, strong-smelling flowers about everywhere, and she had actually
 * a bunch of them round her neck. I feared that the heavy odour would be
 * too much for the dear child in her weak state, so I took them all away
 * and opened a bit of the window to let in a little fresh air. You will be
 * pleased with her, I am sure."
 *
 * She moved off into her boudoir, where she usually breakfasted early. As
 * she had spoken, I watched the Professor's face, and saw it turn ashen
 * grey. He had been able to retain his self-command whilst the poor lady
 * was present, for he knew her state and how mischievous a shock would be;
 * he actually smiled on her as he held open the door for her to pass into
 * her room. But the instant she had disappeared he pulled me, suddenly and
 * forcibly, into the dining-room and closed the door.
 *
 * Then, for the first time in my life, I saw Van Helsing break down. He
 * raised his hands over his head in a sort of mute despair, and then beat
 * his palms together in a helpless way; finally he sat down on a chair,
 * and putting his hands before his face, began to sob, with loud, dry sobs
 * that seemed to come from the very racking of his heart. Then he raised
 * his arms again, as though appealing to the whole universe. "God! God!
 * God!" he said. "What have we done, what has this poor thing done, that
 * we are so sore beset? Is there fate amongst us still, sent down from the
 * pagan world of old, that such things must be, and in such way? This poor
 * mother, all unknowing, and all for the best as she think, does such
 * thing as lose her daughter body and soul; and we must not tell her, we
 * must not even warn her, or she die, and then both die. Oh, how we are
 * beset! How are all the powers of the devils against us!" Suddenly he
 * jumped to his feet. "Come," he said, "come, we must see and act. Devils
 * or no devils, or all the devils at once, it matters not; we fight him
 * all the same." He went to the hall-door for his bag; and together we
 * went up to Lucy's room.
 *
 * Once again I drew up the blind, whilst Van Helsing went towards the bed.
 * This time he did not start as he looked on the poor face with the same
 * awful, waxen pallor as before. He wore a look of stern sadness and
 * infinite pity.
 *
 * "As I expected," he murmured, with that hissing inspiration of his which
 * meant so much. Without a word he went and locked the door, and then
 * began to set out on the little table the instruments for yet another
 * operation of transfusion of blood. I had long ago recognised the
 * necessity, and begun to take off my coat, but he stopped me with a
 * warning hand. "No!" he said. "To-day you must operate. I shall provide.
 * You are weakened already." As he spoke he took off his coat and rolled
 * up his shirt-sleeve.
 *
 * Again the operation; again the narcotic; again some return of colour to
 * the ashy cheeks, and the regular breathing of healthy sleep. This time I
 * watched whilst Van Helsing recruited himself and rested.
 *
 * Presently he took an opportunity of telling Mrs. Westenra that she must
 * not remove anything from Lucy's room without consulting him; that the
 * flowers were of medicinal value, and that the breathing of their odour
 * was a part of the system of cure. Then he took over the care of the case
 * himself, saying that he would watch this night and the next and would
 * send me word when to come.
 *
 * After another hour Lucy waked from her sleep, fresh and bright and
 * seemingly not much the worse for her terrible ordeal.
 *
 * What does it all mean? I am beginning to wonder if my long habit of life
 * amongst the insane is beginning to tell upon my own brain.
 *
 *
 * _Lucy Westenra's Diary._
 *
 * _17 September._--Four days and nights of peace. I am getting so strong
 * again that I hardly know myself. It is as if I had passed through some
 * long nightmare, and had just awakened to see the beautiful sunshine and
 * feel the fresh air of the morning around me. I have a dim
 * half-remembrance of long, anxious times of waiting and fearing; darkness
 * in which there was not even the pain of hope to make present distress
 * more poignant: and then long spells of oblivion, and the rising back to
 * life as a diver coming up through a great press of water. Since,
 * however, Dr. Van Helsing has been with me, all this bad dreaming seems
 * to have passed away; the noises that used to frighten me out of my
 * wits--the flapping against the windows, the distant voices which seemed
 * so close to me, the harsh sounds that came from I know not where and
 * commanded me to do I know not what--have all ceased. I go to bed now
 * without any fear of sleep. I do not even try to keep awake. I have grown
 * quite fond of the garlic, and a boxful arrives for me every day from
 * Haarlem. To-night Dr. Van Helsing is going away, as he has to be for a
 * day in Amsterdam. But I need not be watched; I am well enough to be left
 * alone. Thank God for mother's sake, and dear Arthur's, and for all our
 * friends who have been so kind! I shall not even feel the change, for
 * last night Dr. Van Helsing slept in his chair a lot of the time. I found
 * him asleep twice when I awoke; but I did not fear to go to sleep again,
 * although the boughs or bats or something napped almost angrily against
 * the window-panes.
 *
 *
 * _"The Pall Mall Gazette," 18 September._
 *
 *                            THE ESCAPED WOLF.
 *
 *          PERILOUS ADVENTURE OF OUR INTERVIEWER.
 *
 *          _Interview with the Keeper in the Zoölogical Gardens._
 *
 * After many inquiries and almost as many refusals, and perpetually using
 * the words "Pall Mall Gazette" as a sort of talisman, I managed to find
 * the keeper of the section of the Zoölogical Gardens in which the wolf
 * department is included. Thomas Bilder lives in one of the cottages in
 * the enclosure behind the elephant-house, and was just sitting down to
 * his tea when I found him. Thomas and his wife are hospitable folk,
 * elderly, and without children, and if the specimen I enjoyed of their
 * hospitality be of the average kind, their lives must be pretty
 * comfortable. The keeper would not enter on what he called "business"
 * until the supper was over, and we were all satisfied. Then when the
 * table was cleared, and he had lit his pipe, he said:--
 *
 * "Now, sir, you can go on and arsk me what you want. You'll excoose me
 * refoosin' to talk of perfeshunal subjects afore meals. I gives the
 * wolves and the jackals and the hyenas in all our section their tea afore
 * I begins to arsk them questions."
 *
 * "How do you mean, ask them questions?" I queried, wishful to get him
 * into a talkative humour.
 *
 * "'Ittin' of them over the 'ead with a pole is one way; scratchin' of
 * their hears is another, when gents as is flush wants a bit of a show-orf
 * to their gals. I don't so much mind the fust--the 'ittin' with a pole
 * afore I chucks in their dinner; but I waits till they've 'ad their
 * sherry and kawffee, so to speak, afore I tries on with the
 * ear-scratchin'. Mind you," he added philosophically, "there's a deal of
 * the same nature in us as in them theer animiles. Here's you a-comin' and
 * arskin' of me questions about my business, and I that grumpy-like that
 * only for your bloomin' 'arf-quid I'd 'a' seen you blowed fust 'fore I'd
 * answer. Not even when you arsked me sarcastic-like if I'd like you to
 * arsk the Superintendent if you might arsk me questions. Without offence
 * did I tell yer to go to 'ell?"
 *
 * "You did."
 *
 * "An' when you said you'd report me for usin' of obscene language that
 * was 'ittin' me over the 'ead; but the 'arf-quid made that all right. I
 * weren't a-goin' to fight, so I waited for the food, and did with my 'owl
 * as the wolves, and lions, and tigers does. But, Lor' love yer 'art, now
 * that the old 'ooman has stuck a chunk of her tea-cake in me, an' rinsed
 * me out with her bloomin' old teapot, and I've lit hup, you may scratch
 * my ears for all you're worth, and won't git even a growl out of me.
 * Drive along with your questions. I know what yer a-comin' at, that 'ere
 * escaped wolf."
 *
 * "Exactly. I want you to give me your view of it. Just tell me how it
 * happened; and when I know the facts I'll get you to say what you
 * consider was the cause of it, and how you think the whole affair will
 * end."
 *
 * "All right, guv'nor. This 'ere is about the 'ole story. That 'ere wolf
 * what we called Bersicker was one of three grey ones that came from
 * Norway to Jamrach's, which we bought off him four years ago. He was a
 * nice well-behaved wolf, that never gave no trouble to talk of. I'm more
 * surprised at 'im for wantin' to get out nor any other animile in the
 * place. But, there, you can't trust wolves no more nor women."
 *
 * "Don't you mind him, sir!" broke in Mrs. Tom, with a cheery laugh. "'E's
 * got mindin' the animiles so long that blest if he ain't like a old wolf
 * 'isself! But there ain't no 'arm in 'im."
 *
 * "Well, sir, it was about two hours after feedin' yesterday when I first
 * hear my disturbance. I was makin' up a litter in the monkey-house for a
 * young puma which is ill; but when I heard the yelpin' and 'owlin' I kem
 * away straight. There was Bersicker a-tearin' like a mad thing at the
 * bars as if he wanted to get out. There wasn't much people about that
 * day, and close at hand was only one man, a tall, thin chap, with a 'ook
 * nose and a pointed beard, with a few white hairs runnin' through it. He
 * had a 'ard, cold look and red eyes, and I took a sort of mislike to him,
 * for it seemed as if it was 'im as they was hirritated at. He 'ad white
 * kid gloves on 'is 'ands, and he pointed out the animiles to me and says:
 * 'Keeper, these wolves seem upset at something.'
 *
 * "'Maybe it's you,' says I, for I did not like the airs as he give
 * 'isself. He didn't git angry, as I 'oped he would, but he smiled a kind
 * of insolent smile, with a mouth full of white, sharp teeth. 'Oh no, they
 * wouldn't like me,' 'e says.
 *
 * "'Ow yes, they would,' says I, a-imitatin' of him. 'They always likes a
 * bone or two to clean their teeth on about tea-time, which you 'as a
 * bagful.'
 *
 * "Well, it was a odd thing, but when the animiles see us a-talkin' they
 * lay down, and when I went over to Bersicker he let me stroke his ears
 * same as ever. That there man kem over, and blessed but if he didn't put
 * in his hand and stroke the old wolf's ears too!
 *
 * "'Tyke care,' says I. 'Bersicker is quick.'
 *
 * "'Never mind,' he says. 'I'm used to 'em!'
 *
 * "'Are you in the business yourself?' I says, tyking off my 'at, for a
 * man what trades in wolves, anceterer, is a good friend to keepers.
 *
 * "'No' says he, 'not exactly in the business, but I 'ave made pets of
 * several.' And with that he lifts his 'at as perlite as a lord, and walks
 * away. Old Bersicker kep' a-lookin' arter 'im till 'e was out of sight,
 * and then went and lay down in a corner and wouldn't come hout the 'ole
 * hevening. Well, larst night, so soon as the moon was hup, the wolves
 * here all began a-'owling. There warn't nothing for them to 'owl at.
 * There warn't no one near, except some one that was evidently a-callin' a
 * dog somewheres out back of the gardings in the Park road. Once or twice
 * I went out to see that all was right, and it was, and then the 'owling
 * stopped. Just before twelve o'clock I just took a look round afore
 * turnin' in, an', bust me, but when I kem opposite to old Bersicker's
 * cage I see the rails broken and twisted about and the cage empty. And
 * that's all I know for certing."
 *
 * "Did any one else see anything?"
 *
 * "One of our gard'ners was a-comin' 'ome about that time from a 'armony,
 * when he sees a big grey dog comin' out through the garding 'edges. At
 * least, so he says, but I don't give much for it myself, for if he did 'e
 * never said a word about it to his missis when 'e got 'ome, and it was
 * only after the escape of the wolf was made known, and we had been up all
 * night-a-huntin' of the Park for Bersicker, that he remembered seein'
 * anything. My own belief was that the 'armony 'ad got into his 'ead."
 *
 * "Now, Mr. Bilder, can you account in any way for the escape of the
 * wolf?"
 *
 * "Well, sir," he said, with a suspicious sort of modesty, "I think I can;
 * but I don't know as 'ow you'd be satisfied with the theory."
 *
 * "Certainly I shall. If a man like you, who knows the animals from
 * experience, can't hazard a good guess at any rate, who is even to try?"
 *
 * "Well then, sir, I accounts for it this way; it seems to me that 'ere
 * wolf escaped--simply because he wanted to get out."
 *
 * From the hearty way that both Thomas and his wife laughed at the joke I
 * could see that it had done service before, and that the whole
 * explanation was simply an elaborate sell. I couldn't cope in badinage
 * with the worthy Thomas, but I thought I knew a surer way to his heart,
 * so I said:--
 *
 * "Now, Mr. Bilder, we'll consider that first half-sovereign worked off,
 * and this brother of his is waiting to be claimed when you've told me
 * what you think will happen."
 *
 * "Right y'are, sir," he said briskly. "Ye'll excoose me, I know, for
 * a-chaffin' of ye, but the old woman here winked at me, which was as much
 * as telling me to go on."
 *
 * "Well, I never!" said the old lady.
 *
 * "My opinion is this: that 'ere wolf is a-'idin' of, somewheres. The
 * gard'ner wot didn't remember said he was a-gallopin' northward faster
 * than a horse could go; but I don't believe him, for, yer see, sir,
 * wolves don't gallop no more nor dogs does, they not bein' built that
 * way. Wolves is fine things in a storybook, and I dessay when they gets
 * in packs and does be chivyin' somethin' that's more afeared than they is
 * they can make a devil of a noise and chop it up, whatever it is. But,
 * Lor' bless you, in real life a wolf is only a low creature, not half so
 * clever or bold as a good dog; and not half a quarter so much fight in
 * 'im. This one ain't been used to fightin' or even to providin' for
 * hisself, and more like he's somewhere round the Park a-'idin' an'
 * a-shiverin' of, and, if he thinks at all, wonderin' where he is to get
 * his breakfast from; or maybe he's got down some area and is in a
 * coal-cellar. My eye, won't some cook get a rum start when she sees his
 * green eyes a-shining at her out of the dark! If he can't get food he's
 * bound to look for it, and mayhap he may chance to light on a butcher's
 * shop in time. If he doesn't, and some nursemaid goes a-walkin' orf with
 * a soldier, leavin' of the hinfant in the perambulator--well, then I
 * shouldn't be surprised if the census is one babby the less. That's
 * all."
 *
 * I was handing him the half-sovereign, when something came bobbing up
 * against the window, and Mr. Bilder's face doubled its natural length
 * with surprise.
 *
 * "God bless me!" he said. "If there ain't old Bersicker come back by
 * 'isself!"
 *
 * He went to the door and opened it; a most unnecessary proceeding it
 * seemed to me. I have always thought that a wild animal never looks so
 * well as when some obstacle of pronounced durability is between us; a
 * personal experience has intensified rather than diminished that idea.
 *
 * After all, however, there is nothing like custom, for neither Bilder nor
 * his wife thought any more of the wolf than I should of a dog. The animal
 * itself was as peaceful and well-behaved as that father of all
 * picture-wolves--Red Riding Hood's quondam friend, whilst moving her
 * confidence in masquerade.
 *
 * The whole scene was an unutterable mixture of comedy and pathos. The
 * wicked wolf that for half a day had paralysed London and set all the
 * children in the town shivering in their shoes, was there in a sort of
 * penitent mood, and was received and petted like a sort of vulpine
 * prodigal son. Old Bilder examined him all over with most tender
 * solicitude, and when he had finished with his penitent said:--
 *
 * "There, I knew the poor old chap would get into some kind of trouble;
 * didn't I say it all along? Here's his head all cut and full of broken
 * glass. 'E's been a-gettin' over some bloomin' wall or other. It's a
 * shyme that people are allowed to top their walls with broken bottles.
 * This 'ere's what comes of it. Come along, Bersicker."
 *
 * He took the wolf and locked him up in a cage, with a piece of meat that
 * satisfied, in quantity at any rate, the elementary conditions of the
 * fatted calf, and went off to report.
 *
 * I came off, too, to report the only exclusive information that is given
 * to-day regarding the strange escapade at the Zoo.
 *
 *
 * _Dr. Seward's Diary._
 *
 * _17 September._--I was engaged after dinner in my study posting up my
 * books, which, through press of other work and the many visits to Lucy,
 * had fallen sadly into arrear. Suddenly the door was burst open, and in
 * rushed my patient, with his face distorted with passion. I was
 * thunderstruck, for such a thing as a patient getting of his own accord
 * into the Superintendent's study is almost unknown. Without an instant's
 * pause he made straight at me. He had a dinner-knife in his hand, and,
 * as I saw he was dangerous, I tried to keep the table between us. He was
 * too quick and too strong for me, however; for before I could get my
 * balance he had struck at me and cut my left wrist rather severely.
 * Before he could strike again, however, I got in my right and he was
 * sprawling on his back on the floor. My wrist bled freely, and quite a
 * little pool trickled on to the carpet. I saw that my friend was not
 * intent on further effort, and occupied myself binding up my wrist,
 * keeping a wary eye on the prostrate figure all the time. When the
 * attendants rushed in, and we turned our attention to him, his employment
 * positively sickened me. He was lying on his belly on the floor licking
 * up, like a dog, the blood which had fallen from my wounded wrist. He was
 * easily secured, and, to my surprise, went with the attendants quite
 * placidly, simply repeating over and over again: "The blood is the life!
 * The blood is the life!"
 *
 * I cannot afford to lose blood just at present; I have lost too much of
 * late for my physical good, and then the prolonged strain of Lucy's
 * illness and its horrible phases is telling on me. I am over-excited and
 * weary, and I need rest, rest, rest. Happily Van Helsing has not summoned
 * me, so I need not forego my sleep; to-night I could not well do without
 * it.
 *
 *
 * _Telegram, Van Helsing, Antwerp, to Seward, Carfax._
 *
 * (Sent to Carfax, Sussex, as no county given; delivered late by
 * twenty-two hours.)
 *
 * "_17 September._--Do not fail to be at Hillingham to-night. If not
 * watching all the time frequently, visit and see that flowers are as
 * placed; very important; do not fail. Shall be with you as soon as
 * possible after arrival."
 *
 *
 * _Dr. Seward's Diary._
 *
 * _18 September._--Just off for train to London. The arrival of Van
 * Helsing's telegram filled me with dismay. A whole night lost, and I know
 * by bitter experience what may happen in a night. Of course it is
 * possible that all may be well, but what _may_ have happened? Surely
 * there is some horrible doom hanging over us that every possible accident
 * should thwart us in all we try to do. I shall take this cylinder with
 * me, and then I can complete my entry on Lucy's phonograph.
 *
 *
 * _Memorandum left by Lucy Westenra._
 *
 * _17 September. Night._--I write this and leave it to be seen, so that no
 * one may by any chance get into trouble through me. This is an exact
 * record of what took place to-night. I feel I am dying of weakness, and
 * have barely strength to write, but it must be done if I die in the
 * doing.
 *
 * I went to bed as usual, taking care that the flowers were placed as Dr.
 * Van Helsing directed, and soon fell asleep.
 *
 * I was waked by the flapping at the window, which had begun after that
 * sleep-walking on the cliff at Whitby when Mina saved me, and which now I
 * know so well. I was not afraid, but I did wish that Dr. Seward was in
 * the next room--as Dr. Van Helsing said he would be--so that I might have
 * called him. I tried to go to sleep, but could not. Then there came to me
 * the old fear of sleep, and I determined to keep awake. Perversely sleep
 * would try to come then when I did not want it; so, as I feared to be
 * alone, I opened my door and called out: "Is there anybody there?" There
 * was no answer. I was afraid to wake mother, and so closed my door again.
 * Then outside in the shrubbery I heard a sort of howl like a dog's, but
 * more fierce and deeper. I went to the window and looked out, but could
 * see nothing, except a big bat, which had evidently been buffeting its
 * wings against the window. So I went back to bed again, but determined
 * not to go to sleep. Presently the door opened, and mother looked in;
 * seeing by my moving that I was not asleep, came in, and sat by me. She
 * said to me even more sweetly and softly than her wont:--
 *
 * "I was uneasy about you, darling, and came in to see that you were all
 * right."
 *
 * I feared she might catch cold sitting there, and asked her to come in
 * and sleep with me, so she came into bed, and lay down beside me; she did
 * not take off her dressing gown, for she said she would only stay a while
 * and then go back to her own bed. As she lay there in my arms, and I in
 * hers, the flapping and buffeting came to the window again. She was
 * startled and a little frightened, and cried out: "What is that?" I tried
 * to pacify her, and at last succeeded, and she lay quiet; but I could
 * hear her poor dear heart still beating terribly. After a while there was
 * the low howl again out in the shrubbery, and shortly after there was a
 * crash at the window, and a lot of broken glass was hurled on the floor.
 * The window blind blew back with the wind that rushed in, and in the
 * aperture of the broken panes there was the head of a great, gaunt grey
 * wolf. Mother cried out in a fright, and struggled up into a sitting
 * posture, and clutched wildly at anything that would help her. Amongst
 * other things, she clutched the wreath of flowers that Dr. Van Helsing
 * insisted on my wearing round my neck, and tore it away from me. For a
 * second or two she sat up, pointing at the wolf, and there was a strange
 * and horrible gurgling in her throat; then she fell over--as if struck
 * with lightning, and her head hit my forehead and made me dizzy for a
 * moment or two. The room and all round seemed to spin round. I kept my
 * eyes fixed on the window, but the wolf drew his head back, and a whole
 * myriad of little specks seemed to come blowing in through the broken
 * window, and wheeling and circling round like the pillar of dust that
 * travellers describe when there is a simoon in the desert. I tried to
 * stir, but there was some spell upon me, and dear mother's poor body,
 * which seemed to grow cold already--for her dear heart had ceased to
 * beat--weighed me down; and I remembered no more for a while.
 *
 * The time did not seem long, but very, very awful, till I recovered
 * consciousness again. Somewhere near, a passing bell was tolling; the
 * dogs all round the neighbourhood were howling; and in our shrubbery,
 * seemingly just outside, a nightingale was singing. I was dazed and
 * stupid with pain and terror and weakness, but the sound of the
 * nightingale seemed like the voice of my dead mother come back to comfort
 * me. The sounds seemed to have awakened the maids, too, for I could hear
 * their bare feet pattering outside my door. I called to them, and they
 * came in, and when they saw what had happened, and what it was that lay
 * over me on the bed, they screamed out. The wind rushed in through the
 * broken window, and the door slammed to. They lifted off the body of my
 * dear mother, and laid her, covered up with a sheet, on the bed after I
 * had got up. They were all so frightened and nervous that I directed them
 * to go to the dining-room and have each a glass of wine. The door flew
 * open for an instant and closed again. The maids shrieked, and then went
 * in a body to the dining-room; and I laid what flowers I had on my dear
 * mother's breast. When they were there I remembered what Dr. Van Helsing
 * had told me, but I didn't like to remove them, and, besides, I would
 * have some of the servants to sit up with me now. I was surprised that
 * the maids did not come back. I called them, but got no answer, so I went
 * to the dining-room to look for them.
 *
 * My heart sank when I saw what had happened. They all four lay helpless
 * on the floor, breathing heavily. The decanter of sherry was on the table
 * half full, but there was a queer, acrid smell about. I was suspicious,
 * and examined the decanter. It smelt of laudanum, and looking on the
 * sideboard, I found that the bottle which mother's doctor uses for
 * her--oh! did use--was empty. What am I to do? what am I to do? I am back
 * in the room with mother. I cannot leave her, and I am alone, save for
 * the sleeping servants, whom some one has drugged. Alone with the dead! I
 * dare not go out, for I can hear the low howl of the wolf through the
 * broken window.
 *
 * The air seems full of specks, floating and circling in the draught from
 * the window, and the lights burn blue and dim. What am I to do? God
 * shield me from harm this night! I shall hide this paper in my breast,
 * where they shall find it when they come to lay me out. My dear mother
 * gone! It is time that I go too. Good-bye, dear Arthur, if I should not
 * survive this night. God keep you, dear, and God help me!
 */
/*                                                                             *
 **                                                                           **
 ***                                                                         ***
 ****                                                                       ****
 *****                                                                     *****
 ******                                                                   ******
 *******                                                                 *******
 ******                                                                   ******
 *****                                                                     *****
 ****                                                                       ****
 ***                                                                         ***
 **                                                                           **
 *                                                                             */
/**
 * \page chapter_XII CHAPTER XII: Dr. Seward's Diary
 * DR. SEWARD'S DIARY
 *
 *
 * _18 September._--I drove at once to Hillingham and arrived early.
 * Keeping my cab at the gate, I went up the avenue alone. I knocked gently
 * and rang as quietly as possible, for I feared to disturb Lucy or her
 * mother, and hoped to only bring a servant to the door. After a while,
 * finding no response, I knocked and rang again; still no answer. I cursed
 * the laziness of the servants that they should lie abed at such an
 * hour--for it was now ten o'clock--and so rang and knocked again, but
 * more impatiently, but still without response. Hitherto I had blamed only
 * the servants, but now a terrible fear began to assail me. Was this
 * desolation but another link in the chain of doom which seemed drawing
 * tight around us? Was it indeed a house of death to which I had come, too
 * late? I knew that minutes, even seconds of delay, might mean hours of
 * danger to Lucy, if she had had again one of those frightful relapses;
 * and I went round the house to try if I could find by chance an entry
 * anywhere.
 *
 * I could find no means of ingress. Every window and door was fastened and
 * locked, and I returned baffled to the porch. As I did so, I heard the
 * rapid pit-pat of a swiftly driven horse's feet. They stopped at the
 * gate, and a few seconds later I met Van Helsing running up the avenue.
 * When he saw me, he gasped out:--
 *
 * "Then it was you, and just arrived. How is she? Are we too late? Did you
 * not get my telegram?"
 *
 * I answered as quickly and coherently as I could that I had only got his
 * telegram early in the morning, and had not lost a minute in coming here,
 * and that I could not make any one in the house hear me. He paused and
 * raised his hat as he said solemnly:--
 *
 * "Then I fear we are too late. God's will be done!" With his usual
 * recuperative energy, he went on: "Come. If there be no way open to get
 * in, we must make one. Time is all in all to us now."
 *
 * We went round to the back of the house, where there was a kitchen
 * window. The Professor took a small surgical saw from his case, and
 * handing it to me, pointed to the iron bars which guarded the window. I
 * attacked them at once and had very soon cut through three of them. Then
 * with a long, thin knife we pushed back the fastening of the sashes and
 * opened the window. I helped the Professor in, and followed him. There
 * was no one in the kitchen or in the servants' rooms, which were close at
 * hand. We tried all the rooms as we went along, and in the dining-room,
 * dimly lit by rays of light through the shutters, found four
 * servant-women lying on the floor. There was no need to think them dead,
 * for their stertorous breathing and the acrid smell of laudanum in the
 * room left no doubt as to their condition. Van Helsing and I looked at
 * each other, and as we moved away he said: "We can attend to them later."
 * Then we ascended to Lucy's room. For an instant or two we paused at the
 * door to listen, but there was no sound that we could hear. With white
 * faces and trembling hands, we opened the door gently, and entered the
 * room.
 *
 * How shall I describe what we saw? On the bed lay two women, Lucy and her
 * mother. The latter lay farthest in, and she was covered with a white
 * sheet, the edge of which had been blown back by the draught through the
 * broken window, showing the drawn, white face, with a look of terror
 * fixed upon it. By her side lay Lucy, with face white and still more
 * drawn. The flowers which had been round her neck we found upon her
 * mother's bosom, and her throat was bare, showing the two little wounds
 * which we had noticed before, but looking horribly white and mangled.
 * Without a word the Professor bent over the bed, his head almost touching
 * poor Lucy's breast; then he gave a quick turn of his head, as of one who
 * listens, and leaping to his feet, he cried out to me:--
 *
 * "It is not yet too late! Quick! quick! Bring the brandy!"
 *
 * I flew downstairs and returned with it, taking care to smell and taste
 * it, lest it, too, were drugged like the decanter of sherry which I found
 * on the table. The maids were still breathing, but more restlessly, and I
 * fancied that the narcotic was wearing off. I did not stay to make sure,
 * but returned to Van Helsing. He rubbed the brandy, as on another
 * occasion, on her lips and gums and on her wrists and the palms of her
 * hands. He said to me:--
 *
 * "I can do this, all that can be at the present. You go wake those maids.
 * Flick them in the face with a wet towel, and flick them hard. Make them
 * get heat and fire and a warm bath. This poor soul is nearly as cold as
 * that beside her. She will need be heated before we can do anything
 * more."
 *
 * I went at once, and found little difficulty in waking three of the
 * women. The fourth was only a young girl, and the drug had evidently
 * affected her more strongly, so I lifted her on the sofa and let her
 * sleep. The others were dazed at first, but as remembrance came back to
 * them they cried and sobbed in a hysterical manner. I was stern with
 * them, however, and would not let them talk. I told them that one life
 * was bad enough to lose, and that if they delayed they would sacrifice
 * Miss Lucy. So, sobbing and crying, they went about their way, half clad
 * as they were, and prepared fire and water. Fortunately, the kitchen and
 * boiler fires were still alive, and there was no lack of hot water. We
 * got a bath and carried Lucy out as she was and placed her in it. Whilst
 * we were busy chafing her limbs there was a knock at the hall door. One
 * of the maids ran off, hurried on some more clothes, and opened it. Then
 * she returned and whispered to us that there was a gentleman who had come
 * with a message from Mr. Holmwood. I bade her simply tell him that he
 * must wait, for we could see no one now. She went away with the message,
 * and, engrossed with our work, I clean forgot all about him.
 *
 * I never saw in all my experience the Professor work in such deadly
 * earnest. I knew--as he knew--that it was a stand-up fight with death,
 * and in a pause told him so. He answered me in a way that I did not
 * understand, but with the sternest look that his face could wear:--
 *
 * "If that were all, I would stop here where we are now, and let her fade
 * away into peace, for I see no light in life over her horizon." He went
 * on with his work with, if possible, renewed and more frenzied vigour.
 *
 * Presently we both began to be conscious that the heat was beginning to
 * be of some effect. Lucy's heart beat a trifle more audibly to the
 * stethoscope, and her lungs had a perceptible movement. Van Helsing's
 * face almost beamed, and as we lifted her from the bath and rolled her in
 * a hot sheet to dry her he said to me:--
 *
 * "The first gain is ours! Check to the King!"
 *
 * We took Lucy into another room, which had by now been prepared, and laid
 * her in bed and forced a few drops of brandy down her throat. I noticed
 * that Van Helsing tied a soft silk handkerchief round her throat. She was
 * still unconscious, and was quite as bad as, if not worse than, we had
 * ever seen her.
 *
 * Van Helsing called in one of the women, and told her to stay with her
 * and not to take her eyes off her till we returned, and then beckoned me
 * out of the room.
 *
 * "We must consult as to what is to be done," he said as we descended the
 * stairs. In the hall he opened the dining-room door, and we passed in, he
 * closing the door carefully behind him. The shutters had been opened, but
 * the blinds were already down, with that obedience to the etiquette of
 * death which the British woman of the lower classes always rigidly
 * observes. The room was, therefore, dimly dark. It was, however, light
 * enough for our purposes. Van Helsing's sternness was somewhat relieved
 * by a look of perplexity. He was evidently torturing his mind about
 * something, so I waited for an instant, and he spoke:--
 *
 * "What are we to do now? Where are we to turn for help? We must have
 * another transfusion of blood, and that soon, or that poor girl's life
 * won't be worth an hour's purchase. You are exhausted already; I am
 * exhausted too. I fear to trust those women, even if they would have
 * courage to submit. What are we to do for some one who will open his
 * veins for her?"
 *
 * "What's the matter with me, anyhow?"
 *
 * The voice came from the sofa across the room, and its tones brought
 * relief and joy to my heart, for they were those of Quincey Morris. Van
 * Helsing started angrily at the first sound, but his face softened and a
 * glad look came into his eyes as I cried out: "Quincey Morris!" and
 * rushed towards him with outstretched hands.
 *
 * "What brought you here?" I cried as our hands met.
 *
 * "I guess Art is the cause."
 *
 * He handed me a telegram:--
 *
 * "Have not heard from Seward for three days, and am terribly anxious.
 * Cannot leave. Father still in same condition. Send me word how Lucy is.
 * Do not delay.--HOLMWOOD."
 *
 * "I think I came just in the nick of time. You know you have only to tell
 * me what to do."
 *
 * Van Helsing strode forward, and took his hand, looking him straight in
 * the eyes as he said:--
 *
 * "A brave man's blood is the best thing on this earth when a woman is in
 * trouble. You're a man and no mistake. Well, the devil may work against
 * us for all he's worth, but God sends us men when we want them."
 *
 * Once again we went through that ghastly operation. I have not the heart
 * to go through with the details. Lucy had got a terrible shock and it
 * told on her more than before, for though plenty of blood went into her
 * veins, her body did not respond to the treatment as well as on the other
 * occasions. Her struggle back into life was something frightful to see
 * and hear. However, the action of both heart and lungs improved, and Van
 * Helsing made a subcutaneous injection of morphia, as before, and with
 * good effect. Her faint became a profound slumber. The Professor watched
 * whilst I went downstairs with Quincey Morris, and sent one of the maids
 * to pay off one of the cabmen who were waiting. I left Quincey lying down
 * after having a glass of wine, and told the cook to get ready a good
 * breakfast. Then a thought struck me, and I went back to the room where
 * Lucy now was. When I came softly in, I found Van Helsing with a sheet or
 * two of note-paper in his hand. He had evidently read it, and was
 * thinking it over as he sat with his hand to his brow. There was a look
 * of grim satisfaction in his face, as of one who has had a doubt solved.
 * He handed me the paper saying only: "It dropped from Lucy's breast when
 * we carried her to the bath."
 *
 * When I had read it, I stood looking at the Professor, and after a pause
 * asked him: "In God's name, what does it all mean? Was she, or is she,
 * mad; or what sort of horrible danger is it?" I was so bewildered that I
 * did not know what to say more. Van Helsing put out his hand and took the
 * paper, saying:--
 *
 * "Do not trouble about it now. Forget it for the present. You shall know
 * and understand it all in good time; but it will be later. And now what
 * is it that you came to me to say?" This brought me back to fact, and I
 * was all myself again.
 *
 * "I came to speak about the certificate of death. If we do not act
 * properly and wisely, there may be an inquest, and that paper would have
 * to be produced. I am in hopes that we need have no inquest, for if we
 * had it would surely kill poor Lucy, if nothing else did. I know, and you
 * know, and the other doctor who attended her knows, that Mrs. Westenra
 * had disease of the heart, and we can certify that she died of it. Let us
 * fill up the certificate at once, and I shall take it myself to the
 * registrar and go on to the undertaker."
 *
 * "Good, oh my friend John! Well thought of! Truly Miss Lucy, if she be
 * sad in the foes that beset her, is at least happy in the friends that
 * love her. One, two, three, all open their veins for her, besides one old
 * man. Ah yes, I know, friend John; I am not blind! I love you all the
 * more for it! Now go."
 *
 * In the hall I met Quincey Morris, with a telegram for Arthur telling him
 * that Mrs. Westenra was dead; that Lucy also had been ill, but was now
 * going on better; and that Van Helsing and I were with her. I told him
 * where I was going, and he hurried me out, but as I was going said:--
 *
 * "When you come back, Jack, may I have two words with you all to
 * ourselves?" I nodded in reply and went out. I found no difficulty about
 * the registration, and arranged with the local undertaker to come up in
 * the evening to measure for the coffin and to make arrangements.
 *
 * When I got back Quincey was waiting for me. I told him I would see him
 * as soon as I knew about Lucy, and went up to her room. She was still
 * sleeping, and the Professor seemingly had not moved from his seat at her
 * side. From his putting his finger to his lips, I gathered that he
 * expected her to wake before long and was afraid of forestalling nature.
 * So I went down to Quincey and took him into the breakfast-room, where
 * the blinds were not drawn down, and which was a little more cheerful, or
 * rather less cheerless, than the other rooms. When we were alone, he said
 * to me:--
 *
 * "Jack Seward, I don't want to shove myself in anywhere where I've no
 * right to be; but this is no ordinary case. You know I loved that girl
 * and wanted to marry her; but, although that's all past and gone, I can't
 * help feeling anxious about her all the same. What is it that's wrong
 * with her? The Dutchman--and a fine old fellow he is; I can see
 * that--said, that time you two came into the room, that you must have
 * _another_ transfusion of blood, and that both you and he were exhausted.
 * Now I know well that you medical men speak _in camera_, and that a man
 * must not expect to know what they consult about in private. But this is
 * no common matter, and, whatever it is, I have done my part. Is not that
 * so?"
 *
 * "That's so," I said, and he went on:--
 *
 * "I take it that both you and Van Helsing had done already what I did
 * to-day. Is not that so?"
 *
 * "That's so."
 *
 * "And I guess Art was in it too. When I saw him four days ago down at his
 * own place he looked queer. I have not seen anything pulled down so quick
 * since I was on the Pampas and had a mare that I was fond of go to grass
 * all in a night. One of those big bats that they call vampires had got at
 * her in the night, and what with his gorge and the vein left open, there
 * wasn't enough blood in her to let her stand up, and I had to put a
 * bullet through her as she lay. Jack, if you may tell me without
 * betraying confidence, Arthur was the first, is not that so?" As he spoke
 * the poor fellow looked terribly anxious. He was in a torture of suspense
 * regarding the woman he loved, and his utter ignorance of the terrible
 * mystery which seemed to surround her intensified his pain. His very
 * heart was bleeding, and it took all the manhood of him--and there was a
 * royal lot of it, too--to keep him from breaking down. I paused before
 * answering, for I felt that I must not betray anything which the
 * Professor wished kept secret; but already he knew so much, and guessed
 * so much, that there could be no reason for not answering, so I answered
 * in the same phrase: "That's so."
 *
 * "And how long has this been going on?"
 *
 * "About ten days."
 *
 * "Ten days! Then I guess, Jack Seward, that that poor pretty creature
 * that we all love has had put into her veins within that time the blood
 * of four strong men. Man alive, her whole body wouldn't hold it." Then,
 * coming close to me, he spoke in a fierce half-whisper: "What took it
 * out?"
 *
 * I shook my head. "That," I said, "is the crux. Van Helsing is simply
 * frantic about it, and I am at my wits' end. I can't even hazard a guess.
 * There has been a series of little circumstances which have thrown out
 * all our calculations as to Lucy being properly watched. But these shall
 * not occur again. Here we stay until all be well--or ill." Quincey held
 * out his hand. "Count me in," he said. "You and the Dutchman will tell me
 * what to do, and I'll do it."
 *
 * When she woke late in the afternoon, Lucy's first movement was to feel
 * in her breast, and, to my surprise, produced the paper which Van Helsing
 * had given me to read. The careful Professor had replaced it where it had
 * come from, lest on waking she should be alarmed. Her eye then lit on Van
 * Helsing and on me too, and gladdened. Then she looked around the room,
 * and seeing where she was, shuddered; she gave a loud cry, and put her
 * poor thin hands before her pale face. We both understood what that
 * meant--that she had realised to the full her mother's death; so we tried
 * what we could to comfort her. Doubtless sympathy eased her somewhat, but
 * she was very low in thought and spirit, and wept silently and weakly for
 * a long time. We told her that either or both of us would now remain with
 * her all the time, and that seemed to comfort her. Towards dusk she fell
 * into a doze. Here a very odd thing occurred. Whilst still asleep she
 * took the paper from her breast and tore it in two. Van Helsing stepped
 * over and took the pieces from her. All the same, however, she went on
 * with the action of tearing, as though the material were still in her
 * hands; finally she lifted her hands and opened them as though scattering
 * the fragments. Van Helsing seemed surprised, and his brows gathered as
 * if in thought, but he said nothing.
 *
 *        *       *       *       *       *
 *
 * _19 September._--All last night she slept fitfully, being always afraid
 * to sleep, and something weaker when she woke from it. The Professor and
 * I took it in turns to watch, and we never left her for a moment
 * unattended. Quincey Morris said nothing about his intention, but I knew
 * that all night long he patrolled round and round the house.
 *
 * When the day came, its searching light showed the ravages in poor Lucy's
 * strength. She was hardly able to turn her head, and the little
 * nourishment which she could take seemed to do her no good. At times she
 * slept, and both Van Helsing and I noticed the difference in her, between
 * sleeping and waking. Whilst asleep she looked stronger, although more
 * haggard, and her breathing was softer; her open mouth showed the pale
 * gums drawn back from the teeth, which thus looked positively longer and
 * sharper than usual; when she woke the softness of her eyes evidently
 * changed the expression, for she looked her own self, although a dying
 * one. In the afternoon she asked for Arthur, and we telegraphed for him.
 * Quincey went off to meet him at the station.
 *
 * When he arrived it was nearly six o'clock, and the sun was setting full
 * and warm, and the red light streamed in through the window and gave more
 * colour to the pale cheeks. When he saw her, Arthur was simply choking
 * with emotion, and none of us could speak. In the hours that had passed,
 * the fits of sleep, or the comatose condition that passed for it, had
 * grown more frequent, so that the pauses when conversation was possible
 * were shortened. Arthur's presence, however, seemed to act as a
 * stimulant; she rallied a little, and spoke to him more brightly than she
 * had done since we arrived. He too pulled himself together, and spoke as
 * cheerily as he could, so that the best was made of everything.
 *
 * It was now nearly one o'clock, and he and Van Helsing are sitting with
 * her. I am to relieve them in a quarter of an hour, and I am entering
 * this on Lucy's phonograph. Until six o'clock they are to try to rest. I
 * fear that to-morrow will end our watching, for the shock has been too
 * great; the poor child cannot rally. God help us all.
 *
 *
 * _Letter, Mina Harker to Lucy Westenra._
 *
 * (Unopened by her.)
 *
 * "_17 September._
 *
 * "My dearest Lucy,--
 *
 * "It seems _an age_ since I heard from you, or indeed since I wrote. You
 * will pardon me, I know, for all my faults when you have read all my
 * budget of news. Well, I got my husband back all right; when we arrived
 * at Exeter there was a carriage waiting for us, and in it, though he had
 * an attack of gout, Mr. Hawkins. He took us to his house, where there
 * were rooms for us all nice and comfortable, and we dined together. After
 * dinner Mr. Hawkins said:--
 *
 * "'My dears, I want to drink your health and prosperity; and may every
 * blessing attend you both. I know you both from children, and have, with
 * love and pride, seen you grow up. Now I want you to make your home here
 * with me. I have left to me neither chick nor child; all are gone, and in
 * my will I have left you everything.' I cried, Lucy dear, as Jonathan and
 * the old man clasped hands. Our evening was a very, very happy one.
 *
 * "So here we are, installed in this beautiful old house, and from both my
 * bedroom and the drawing-room I can see the great elms of the cathedral
 * close, with their great black stems standing out against the old yellow
 * stone of the cathedral and I can hear the rooks overhead cawing and
 * cawing and chattering and gossiping all day, after the manner of
 * rooks--and humans. I am busy, I need not tell you, arranging things and
 * housekeeping. Jonathan and Mr. Hawkins are busy all day; for, now that
 * Jonathan is a partner, Mr. Hawkins wants to tell him all about the
 * clients.
 *
 * "How is your dear mother getting on? I wish I could run up to town for a
 * day or two to see you, dear, but I dare not go yet, with so much on my
 * shoulders; and Jonathan wants looking after still. He is beginning to
 * put some flesh on his bones again, but he was terribly weakened by the
 * long illness; even now he sometimes starts out of his sleep in a sudden
 * way and awakes all trembling until I can coax him back to his usual
 * placidity. However, thank God, these occasions grow less frequent as the
 * days go on, and they will in time pass away altogether, I trust. And now
 * I have told you my news, let me ask yours. When are you to be married,
 * and where, and who is to perform the ceremony, and what are you to wear,
 * and is it to be a public or a private wedding? Tell me all about it,
 * dear; tell me all about everything, for there is nothing which interests
 * you which will not be dear to me. Jonathan asks me to send his
 * 'respectful duty,' but I do not think that is good enough from the
 * junior partner of the important firm Hawkins & Harker; and so, as you
 * love me, and he loves me, and I love you with all the moods and tenses
 * of the verb, I send you simply his 'love' instead. Good-bye, my dearest
 * Lucy, and all blessings on you.
 *
 * "Yours,
 *
 * "MINA HARKER."
 *
 *
 * _Report from Patrick Hennessey, M. D., M. R. C. S. L. K. Q. C. P. I.,
 * etc., etc., to John Seward, M. D._
 *
 * "_20 September._
 *
 * "My dear Sir,--
 *
 * "In accordance with your wishes, I enclose report of the conditions of
 * everything left in my charge.... With regard to patient, Renfield, there
 * is more to say. He has had another outbreak, which might have had a
 * dreadful ending, but which, as it fortunately happened, was unattended
 * with any unhappy results. This afternoon a carrier's cart with two men
 * made a call at the empty house whose grounds abut on ours--the house to
 * which, you will remember, the patient twice ran away. The men stopped at
 * our gate to ask the porter their way, as they were strangers. I was
 * myself looking out of the study window, having a smoke after dinner, and
 * saw one of them come up to the house. As he passed the window of
 * Renfield's room, the patient began to rate him from within, and called
 * him all the foul names he could lay his tongue to. The man, who seemed a
 * decent fellow enough, contented himself by telling him to "shut up for a
 * foul-mouthed beggar," whereon our man accused him of robbing him and
 * wanting to murder him and said that he would hinder him if he were to
 * swing for it. I opened the window and signed to the man not to notice,
 * so he contented himself after looking the place over and making up his
 * mind as to what kind of a place he had got to by saying: 'Lor' bless
 * yer, sir, I wouldn't mind what was said to me in a bloomin' madhouse. I
 * pity ye and the guv'nor for havin' to live in the house with a wild
 * beast like that.' Then he asked his way civilly enough, and I told him
 * where the gate of the empty house was; he went away, followed by threats
 * and curses and revilings from our man. I went down to see if I could
 * make out any cause for his anger, since he is usually such a
 * well-behaved man, and except his violent fits nothing of the kind had
 * ever occurred. I found him, to my astonishment, quite composed and most
 * genial in his manner. I tried to get him to talk of the incident, but he
 * blandly asked me questions as to what I meant, and led me to believe
 * that he was completely oblivious of the affair. It was, I am sorry to
 * say, however, only another instance of his cunning, for within half an
 * hour I heard of him again. This time he had broken out through the
 * window of his room, and was running down the avenue. I called to the
 * attendants to follow me, and ran after him, for I feared he was intent
 * on some mischief. My fear was justified when I saw the same cart which
 * had passed before coming down the road, having on it some great wooden
 * boxes. The men were wiping their foreheads, and were flushed in the
 * face, as if with violent exercise. Before I could get up to him the
 * patient rushed at them, and pulling one of them off the cart, began to
 * knock his head against the ground. If I had not seized him just at the
 * moment I believe he would have killed the man there and then. The other
 * fellow jumped down and struck him over the head with the butt-end of his
 * heavy whip. It was a terrible blow; but he did not seem to mind it, but
 * seized him also, and struggled with the three of us, pulling us to and
 * fro as if we were kittens. You know I am no light weight, and the others
 * were both burly men. At first he was silent in his fighting; but as we
 * began to master him, and the attendants were putting a strait-waistcoat
 * on him, he began to shout: 'I'll frustrate them! They shan't rob me!
 * they shan't murder me by inches! I'll fight for my Lord and Master!' and
 * all sorts of similar incoherent ravings. It was with very considerable
 * difficulty that they got him back to the house and put him in the padded
 * room. One of the attendants, Hardy, had a finger broken. However, I set
 * it all right; and he is going on well.
 *
 * "The two carriers were at first loud in their threats of actions for
 * damages, and promised to rain all the penalties of the law on us. Their
 * threats were, however, mingled with some sort of indirect apology for
 * the defeat of the two of them by a feeble madman. They said that if it
 * had not been for the way their strength had been spent in carrying and
 * raising the heavy boxes to the cart they would have made short work of
 * him. They gave as another reason for their defeat the extraordinary
 * state of drouth to which they had been reduced by the dusty nature of
 * their occupation and the reprehensible distance from the scene of their
 * labours of any place of public entertainment. I quite understood their
 * drift, and after a stiff glass of grog, or rather more of the same, and
 * with each a sovereign in hand, they made light of the attack, and swore
 * that they would encounter a worse madman any day for the pleasure of
 * meeting so 'bloomin' good a bloke' as your correspondent. I took their
 * names and addresses, in case they might be needed. They are as
 * follows:--Jack Smollet, of Dudding's Rents, King George's Road, Great
 * Walworth, and Thomas Snelling, Peter Farley's Row, Guide Court, Bethnal
 * Green. They are both in the employment of Harris & Sons, Moving and
 * Shipment Company, Orange Master's Yard, Soho.
 *
 * "I shall report to you any matter of interest occurring here, and shall
 * wire you at once if there is anything of importance.
 *
 * "Believe me, dear Sir,
 *
 * "Yours faithfully,
 *
 * "PATRICK HENNESSEY."
 *
 *
 * _Letter, Mina Harker to Lucy Westenra_.
 *
 * (Unopened by her.)
 *
 * "_18 September._
 *
 * "My dearest Lucy,--
 *
 * "Such a sad blow has befallen us. Mr. Hawkins has died very suddenly.
 * Some may not think it so sad for us, but we had both come to so love him
 * that it really seems as though we had lost a father. I never knew either
 * father or mother, so that the dear old man's death is a real blow to me.
 * Jonathan is greatly distressed. It is not only that he feels sorrow,
 * deep sorrow, for the dear, good man who has befriended him all his life,
 * and now at the end has treated him like his own son and left him a
 * fortune which to people of our modest bringing up is wealth beyond the
 * dream of avarice, but Jonathan feels it on another account. He says the
 * amount of responsibility which it puts upon him makes him nervous. He
 * begins to doubt himself. I try to cheer him up, and _my_ belief in _him_
 * helps him to have a belief in himself. But it is here that the grave
 * shock that he experienced tells upon him the most. Oh, it is too hard
 * that a sweet, simple, noble, strong nature such as his--a nature which
 * enabled him by our dear, good friend's aid to rise from clerk to master
 * in a few years--should be so injured that the very essence of its
 * strength is gone. Forgive me, dear, if I worry you with my troubles in
 * the midst of your own happiness; but, Lucy dear, I must tell some one,
 * for the strain of keeping up a brave and cheerful appearance to Jonathan
 * tries me, and I have no one here that I can confide in. I dread coming
 * up to London, as we must do the day after to-morrow; for poor Mr.
 * Hawkins left in his will that he was to be buried in the grave with his
 * father. As there are no relations at all, Jonathan will have to be chief
 * mourner. I shall try to run over to see you, dearest, if only for a few
 * minutes. Forgive me for troubling you. With all blessings,
 *
 * "Your loving
 *
 * "MINA HARKER."
 *
 *
 * _Dr. Seward's Diary._
 *
 * _20 September._--Only resolution and habit can let me make an entry
 * to-night. I am too miserable, too low-spirited, too sick of the world
 * and all in it, including life itself, that I would not care if I heard
 * this moment the flapping of the wings of the angel of death. And he has
 * been flapping those grim wings to some purpose of late--Lucy's mother
 * and Arthur's father, and now.... Let me get on with my work.
 *
 * I duly relieved Van Helsing in his watch over Lucy. We wanted Arthur to
 * go to rest also, but he refused at first. It was only when I told him
 * that we should want him to help us during the day, and that we must not
 * all break down for want of rest, lest Lucy should suffer, that he agreed
 * to go. Van Helsing was very kind to him. "Come, my child," he said;
 * "come with me. You are sick and weak, and have had much sorrow and much
 * mental pain, as well as that tax on your strength that we know of. You
 * must not be alone; for to be alone is to be full of fears and alarms.
 * Come to the drawing-room, where there is a big fire, and there are two
 * sofas. You shall lie on one, and I on the other, and our sympathy will
 * be comfort to each other, even though we do not speak, and even if we
 * sleep." Arthur went off with him, casting back a longing look on Lucy's
 * face, which lay in her pillow, almost whiter than the lawn. She lay
 * quite still, and I looked round the room to see that all was as it
 * should be. I could see that the Professor had carried out in this room,
 * as in the other, his purpose of using the garlic; the whole of the
 * window-sashes reeked with it, and round Lucy's neck, over the silk
 * handkerchief which Van Helsing made her keep on, was a rough chaplet of
 * the same odorous flowers. Lucy was breathing somewhat stertorously, and
 * her face was at its worst, for the open mouth showed the pale gums. Her
 * teeth, in the dim, uncertain light, seemed longer and sharper than they
 * had been in the morning. In particular, by some trick of the light, the
 * canine teeth looked longer and sharper than the rest. I sat down by her,
 * and presently she moved uneasily. At the same moment there came a sort
 * of dull flapping or buffeting at the window. I went over to it softly,
 * and peeped out by the corner of the blind. There was a full moonlight,
 * and I could see that the noise was made by a great bat, which wheeled
 * round--doubtless attracted by the light, although so dim--and every now
 * and again struck the window with its wings. When I came back to my seat,
 * I found that Lucy had moved slightly, and had torn away the garlic
 * flowers from her throat. I replaced them as well as I could, and sat
 * watching her.
 *
 * Presently she woke, and I gave her food, as Van Helsing had prescribed.
 * She took but a little, and that languidly. There did not seem to be with
 * her now the unconscious struggle for life and strength that had hitherto
 * so marked her illness. It struck me as curious that the moment she
 * became conscious she pressed the garlic flowers close to her. It was
 * certainly odd that whenever she got into that lethargic state, with the
 * stertorous breathing, she put the flowers from her; but that when she
 * waked she clutched them close. There was no possibility of making any
 * mistake about this, for in the long hours that followed, she had many
 * spells of sleeping and waking and repeated both actions many times.
 *
 * At six o'clock Van Helsing came to relieve me. Arthur had then fallen
 * into a doze, and he mercifully let him sleep on. When he saw Lucy's face
 * I could hear the sissing indraw of his breath, and he said to me in a
 * sharp whisper: "Draw up the blind; I want light!" Then he bent down,
 * and, with his face almost touching Lucy's, examined her carefully. He
 * removed the flowers and lifted the silk handkerchief from her throat. As
 * he did so he started back, and I could hear his ejaculation, "Mein
 * Gott!" as it was smothered in his throat. I bent over and looked, too,
 * and as I noticed some queer chill came over me.
 *
 * The wounds on the throat had absolutely disappeared.
 *
 * For fully five minutes Van Helsing stood looking at her, with his face
 * at its sternest. Then he turned to me and said calmly:--
 *
 * "She is dying. It will not be long now. It will be much difference, mark
 * me, whether she dies conscious or in her sleep. Wake that poor boy, and
 * let him come and see the last; he trusts us, and we have promised him."
 *
 * I went to the dining-room and waked him. He was dazed for a moment, but
 * when he saw the sunlight streaming in through the edges of the shutters
 * he thought he was late, and expressed his fear. I assured him that Lucy
 * was still asleep, but told him as gently as I could that both Van
 * Helsing and I feared that the end was near. He covered his face with his
 * hands, and slid down on his knees by the sofa, where he remained,
 * perhaps a minute, with his head buried, praying, whilst his shoulders
 * shook with grief. I took him by the hand and raised him up. "Come," I
 * said, "my dear old fellow, summon all your fortitude: it will be best
 * and easiest for her."
 *
 * When we came into Lucy's room I could see that Van Helsing had, with
 * his usual forethought, been putting matters straight and making
 * everything look as pleasing as possible. He had even brushed Lucy's
 * hair, so that it lay on the pillow in its usual sunny ripples. When we
 * came into the room she opened her eyes, and seeing him, whispered
 * softly:--
 *
 * "Arthur! Oh, my love, I am so glad you have come!" He was stooping to
 * kiss her, when Van Helsing motioned him back. "No," he whispered, "not
 * yet! Hold her hand; it will comfort her more."
 *
 * So Arthur took her hand and knelt beside her, and she looked her best,
 * with all the soft lines matching the angelic beauty of her eyes. Then
 * gradually her eyes closed, and she sank to sleep. For a little bit her
 * breast heaved softly, and her breath came and went like a tired child's.
 *
 * And then insensibly there came the strange change which I had noticed in
 * the night. Her breathing grew stertorous, the mouth opened, and the pale
 * gums, drawn back, made the teeth look longer and sharper than ever. In a
 * sort of sleep-waking, vague, unconscious way she opened her eyes, which
 * were now dull and hard at once, and said in a soft, voluptuous voice,
 * such as I had never heard from her lips:--
 *
 * "Arthur! Oh, my love, I am so glad you have come! Kiss me!" Arthur bent
 * eagerly over to kiss her; but at that instant Van Helsing, who, like me,
 * had been startled by her voice, swooped upon him, and catching him by
 * the neck with both hands, dragged him back with a fury of strength which
 * I never thought he could have possessed, and actually hurled him almost
 * across the room.
 *
 * "Not for your life!" he said; "not for your living soul and hers!" And
 * he stood between them like a lion at bay.
 *
 * Arthur was so taken aback that he did not for a moment know what to do
 * or say; and before any impulse of violence could seize him he realised
 * the place and the occasion, and stood silent, waiting.
 *
 * I kept my eyes fixed on Lucy, as did Van Helsing, and we saw a spasm as
 * of rage flit like a shadow over her face; the sharp teeth champed
 * together. Then her eyes closed, and she breathed heavily.
 *
 * Very shortly after she opened her eyes in all their softness, and
 * putting out her poor, pale, thin hand, took Van Helsing's great brown
 * one; drawing it to her, she kissed it. "My true friend," she said, in a
 * faint voice, but with untellable pathos, "My true friend, and his! Oh,
 * guard him, and give me peace!"
 *
 * "I swear it!" he said solemnly, kneeling beside her and holding up his
 * hand, as one who registers an oath. Then he turned to Arthur, and said
 * to him: "Come, my child, take her hand in yours, and kiss her on the
 * forehead, and only once."
 *
 * Their eyes met instead of their lips; and so they parted.
 *
 * Lucy's eyes closed; and Van Helsing, who had been watching closely, took
 * Arthur's arm, and drew him away.
 *
 * And then Lucy's breathing became stertorous again, and all at once it
 * ceased.
 *
 * "It is all over," said Van Helsing. "She is dead!"
 *
 * I took Arthur by the arm, and led him away to the drawing-room, where he
 * sat down, and covered his face with his hands, sobbing in a way that
 * nearly broke me down to see.
 *
 * I went back to the room, and found Van Helsing looking at poor Lucy, and
 * his face was sterner than ever. Some change had come over her body.
 * Death had given back part of her beauty, for her brow and cheeks had
 * recovered some of their flowing lines; even the lips had lost their
 * deadly pallor. It was as if the blood, no longer needed for the working
 * of the heart, had gone to make the harshness of death as little rude as
 * might be.
 *
 *     "We thought her dying whilst she slept,
 *         And sleeping when she died."
 *
 * I stood beside Van Helsing, and said:--
 *
 * "Ah, well, poor girl, there is peace for her at last. It is the end!"
 *
 * He turned to me, and said with grave solemnity:--
 *
 * "Not so; alas! not so. It is only the beginning!"
 *
 * When I asked him what he meant, he only shook his head and answered:--
 *
 * "We can do nothing as yet. Wait and see."
 */
/*                                                                             *
 **                                                                           **
 ***                                                                         ***
 ****                                                                       ****
 *****                                                                     *****
 ******                                                                   ******
 *******                                                                 *******
 ******                                                                   ******
 *****                                                                     *****
 ****                                                                       ****
 ***                                                                         ***
 **                                                                           **
 *                                                                             */
/**
 * \page chapter_XIII CHAPTER XIII: Dr. Seward's Diary
 * DR. SEWARD'S DIARY--_continued_.
 *
 *
 * The funeral was arranged for the next succeeding day, so that Lucy and
 * her mother might be buried together. I attended to all the ghastly
 * formalities, and the urbane undertaker proved that his staff were
 * afflicted--or blessed--with something of his own obsequious suavity.
 * Even the woman who performed the last offices for the dead remarked to
 * me, in a confidential, brother-professional way, when she had come out
 * from the death-chamber:--
 *
 * "She makes a very beautiful corpse, sir. It's quite a privilege to
 * attend on her. It's not too much to say that she will do credit to our
 * establishment!"
 *
 * I noticed that Van Helsing never kept far away. This was possible from
 * the disordered state of things in the household. There were no relatives
 * at hand; and as Arthur had to be back the next day to attend at his
 * father's funeral, we were unable to notify any one who should have been
 * bidden. Under the circumstances, Van Helsing and I took it upon
 * ourselves to examine papers, etc. He insisted upon looking over Lucy's
 * papers himself. I asked him why, for I feared that he, being a
 * foreigner, might not be quite aware of English legal requirements, and
 * so might in ignorance make some unnecessary trouble. He answered me:--
 *
 * "I know; I know. You forget that I am a lawyer as well as a doctor. But
 * this is not altogether for the law. You knew that, when you avoided the
 * coroner. I have more than him to avoid. There may be papers more--such
 * as this."
 *
 * As he spoke he took from his pocket-book the memorandum which had been
 * in Lucy's breast, and which she had torn in her sleep.
 *
 * "When you find anything of the solicitor who is for the late Mrs.
 * Westenra, seal all her papers, and write him to-night. For me, I watch
 * here in the room and in Miss Lucy's old room all night, and I myself
 * search for what may be. It is not well that her very thoughts go into
 * the hands of strangers."
 *
 * I went on with my part of the work, and in another half hour had found
 * the name and address of Mrs. Westenra's solicitor and had written to
 * him. All the poor lady's papers were in order; explicit directions
 * regarding the place of burial were given. I had hardly sealed the
 * letter, when, to my surprise, Van Helsing walked into the room,
 * saying:--
 *
 * "Can I help you, friend John? I am free, and if I may, my service is to
 * you."
 *
 * "Have you got what you looked for?" I asked, to which he replied:--
 *
 * "I did not look for any specific thing. I only hoped to find, and find I
 * have, all that there was--only some letters and a few memoranda, and a
 * diary new begun. But I have them here, and we shall for the present say
 * nothing of them. I shall see that poor lad to-morrow evening, and, with
 * his sanction, I shall use some."
 *
 * When we had finished the work in hand, he said to me:--
 *
 * "And now, friend John, I think we may to bed. We want sleep, both you
 * and I, and rest to recuperate. To-morrow we shall have much to do, but
 * for the to-night there is no need of us. Alas!"
 *
 * Before turning in we went to look at poor Lucy. The undertaker had
 * certainly done his work well, for the room was turned into a small
 * _chapelle ardente_. There was a wilderness of beautiful white flowers,
 * and death was made as little repulsive as might be. The end of the
 * winding-sheet was laid over the face; when the Professor bent over and
 * turned it gently back, we both started at the beauty before us, the tall
 * wax candles showing a sufficient light to note it well. All Lucy's
 * loveliness had come back to her in death, and the hours that had passed,
 * instead of leaving traces of "decay's effacing fingers," had but
 * restored the beauty of life, till positively I could not believe my eyes
 * that I was looking at a corpse.
 *
 * The Professor looked sternly grave. He had not loved her as I had, and
 * there was no need for tears in his eyes. He said to me: "Remain till I
 * return," and left the room. He came back with a handful of wild garlic
 * from the box waiting in the hall, but which had not been opened, and
 * placed the flowers amongst the others on and around the bed. Then he
 * took from his neck, inside his collar, a little gold crucifix, and
 * placed it over the mouth. He restored the sheet to its place, and we
 * came away.
 *
 * I was undressing in my own room, when, with a premonitory tap at the
 * door, he entered, and at once began to speak:--
 *
 * "To-morrow I want you to bring me, before night, a set of post-mortem
 * knives."
 *
 * "Must we make an autopsy?" I asked.
 *
 * "Yes and no. I want to operate, but not as you think. Let me tell you
 * now, but not a word to another. I want to cut off her head and take out
 * her heart. Ah! you a surgeon, and so shocked! You, whom I have seen with
 * no tremble of hand or heart, do operations of life and death that make
 * the rest shudder. Oh, but I must not forget, my dear friend John, that
 * you loved her; and I have not forgotten it, for it is I that shall
 * operate, and you must only help. I would like to do it to-night, but for
 * Arthur I must not; he will be free after his father's funeral to-morrow,
 * and he will want to see her--to see _it_. Then, when she is coffined
 * ready for the next day, you and I shall come when all sleep. We shall
 * unscrew the coffin-lid, and shall do our operation: and then replace
 * all, so that none know, save we alone."
 *
 * "But why do it at all? The girl is dead. Why mutilate her poor body
 * without need? And if there is no necessity for a post-mortem and nothing
 * to gain by it--no good to her, to us, to science, to human
 * knowledge--why do it? Without such it is monstrous."
 *
 * For answer he put his hand on my shoulder, and said, with infinite
 * tenderness:--
 *
 * "Friend John, I pity your poor bleeding heart; and I love you the more
 * because it does so bleed. If I could, I would take on myself the burden
 * that you do bear. But there are things that you know not, but that you
 * shall know, and bless me for knowing, though they are not pleasant
 * things. John, my child, you have been my friend now many years, and yet
 * did you ever know me to do any without good cause? I may err--I am but
 * man; but I believe in all I do. Was it not for these causes that you
 * send for me when the great trouble came? Yes! Were you not amazed, nay
 * horrified, when I would not let Arthur kiss his love--though she was
 * dying--and snatched him away by all my strength? Yes! And yet you saw
 * how she thanked me, with her so beautiful dying eyes, her voice, too, so
 * weak, and she kiss my rough old hand and bless me? Yes! And did you not
 * hear me swear promise to her, that so she closed her eyes grateful? Yes!
 *
 * "Well, I have good reason now for all I want to do. You have for many
 * years trust me; you have believe me weeks past, when there be things so
 * strange that you might have well doubt. Believe me yet a little, friend
 * John. If you trust me not, then I must tell what I think; and that is
 * not perhaps well. And if I work--as work I shall, no matter trust or no
 * trust--without my friend trust in me, I work with heavy heart and feel,
 * oh! so lonely when I want all help and courage that may be!" He paused a
 * moment and went on solemnly: "Friend John, there are strange and
 * terrible days before us. Let us not be two, but one, that so we work to
 * a good end. Will you not have faith in me?"
 *
 * I took his hand, and promised him. I held my door open as he went away,
 * and watched him go into his room and close the door. As I stood without
 * moving, I saw one of the maids pass silently along the passage--she had
 * her back towards me, so did not see me--and go into the room where Lucy
 * lay. The sight touched me. Devotion is so rare, and we are so grateful
 * to those who show it unasked to those we love. Here was a poor girl
 * putting aside the terrors which she naturally had of death to go watch
 * alone by the bier of the mistress whom she loved, so that the poor clay
 * might not be lonely till laid to eternal rest....
 *
 *        *       *       *       *       *
 *
 * I must have slept long and soundly, for it was broad daylight when Van
 * Helsing waked me by coming into my room. He came over to my bedside and
 * said:--
 *
 * "You need not trouble about the knives; we shall not do it."
 *
 * "Why not?" I asked. For his solemnity of the night before had greatly
 * impressed me.
 *
 * "Because," he said sternly, "it is too late--or too early. See!" Here he
 * held up the little golden crucifix. "This was stolen in the night."
 *
 * "How, stolen," I asked in wonder, "since you have it now?"
 *
 * "Because I get it back from the worthless wretch who stole it, from the
 * woman who robbed the dead and the living. Her punishment will surely
 * come, but not through me; she knew not altogether what she did and thus
 * unknowing, she only stole. Now we must wait."
 *
 * He went away on the word, leaving me with a new mystery to think of, a
 * new puzzle to grapple with.
 *
 * The forenoon was a dreary time, but at noon the solicitor came: Mr.
 * Marquand, of Wholeman, Sons, Marquand & Lidderdale. He was very genial
 * and very appreciative of what we had done, and took off our hands all
 * cares as to details. During lunch he told us that Mrs. Westenra had for
 * some time expected sudden death from her heart, and had put her affairs
 * in absolute order; he informed us that, with the exception of a certain
 * entailed property of Lucy's father's which now, in default of direct
 * issue, went back to a distant branch of the family, the whole estate,
 * real and personal, was left absolutely to Arthur Holmwood. When he had
 * told us so much he went on:--
 *
 * "Frankly we did our best to prevent such a testamentary disposition, and
 * pointed out certain contingencies that might leave her daughter either
 * penniless or not so free as she should be to act regarding a matrimonial
 * alliance. Indeed, we pressed the matter so far that we almost came into
 * collision, for she asked us if we were or were not prepared to carry out
 * her wishes. Of course, we had then no alternative but to accept. We were
 * right in principle, and ninety-nine times out of a hundred we should
 * have proved, by the logic of events, the accuracy of our judgment.
 * Frankly, however, I must admit that in this case any other form of
 * disposition would have rendered impossible the carrying out of her
 * wishes. For by her predeceasing her daughter the latter would have come
 * into possession of the property, and, even had she only survived her
 * mother by five minutes, her property would, in case there were no
 * will--and a will was a practical impossibility in such a case--have been
 * treated at her decease as under intestacy. In which case Lord Godalming,
 * though so dear a friend, would have had no claim in the world; and the
 * inheritors, being remote, would not be likely to abandon their just
 * rights, for sentimental reasons regarding an entire stranger. I assure
 * you, my dear sirs, I am rejoiced at the result, perfectly rejoiced."
 *
 * He was a good fellow, but his rejoicing at the one little part--in which
 * he was officially interested--of so great a tragedy, was an
 * object-lesson in the limitations of sympathetic understanding.
 *
 * He did not remain long, but said he would look in later in the day and
 * see Lord Godalming. His coming, however, had been a certain comfort to
 * us, since it assured us that we should not have to dread hostile
 * criticism as to any of our acts. Arthur was expected at five o'clock, so
 * a little before that time we visited the death-chamber. It was so in
 * very truth, for now both mother and daughter lay in it. The undertaker,
 * true to his craft, had made the best display he could of his goods, and
 * there was a mortuary air about the place that lowered our spirits at
 * once. Van Helsing ordered the former arrangement to be adhered to,
 * explaining that, as Lord Godalming was coming very soon, it would be
 * less harrowing to his feelings to see all that was left of his _fiancée_
 * quite alone. The undertaker seemed shocked at his own stupidity and
 * exerted himself to restore things to the condition in which we left them
 * the night before, so that when Arthur came such shocks to his feelings
 * as we could avoid were saved.
 *
 * Poor fellow! He looked desperately sad and broken; even his stalwart
 * manhood seemed to have shrunk somewhat under the strain of his
 * much-tried emotions. He had, I knew, been very genuinely and devotedly
 * attached to his father; and to lose him, and at such a time, was a
 * bitter blow to him. With me he was warm as ever, and to Van Helsing he
 * was sweetly courteous; but I could not help seeing that there was some
 * constraint with him. The Professor noticed it, too, and motioned me to
 * bring him upstairs. I did so, and left him at the door of the room, as I
 * felt he would like to be quite alone with her, but he took my arm and
 * led me in, saying huskily:--
 *
 * "You loved her too, old fellow; she told me all about it, and there was
 * no friend had a closer place in her heart than you. I don't know how to
 * thank you for all you have done for her. I can't think yet...."
 *
 * Here he suddenly broke down, and threw his arms round my shoulders and
 * laid his head on my breast, crying:--
 *
 * "Oh, Jack! Jack! What shall I do! The whole of life seems gone from me
 * all at once, and there is nothing in the wide world for me to live for."
 *
 * I comforted him as well as I could. In such cases men do not need much
 * expression. A grip of the hand, the tightening of an arm over the
 * shoulder, a sob in unison, are expressions of sympathy dear to a man's
 * heart. I stood still and silent till his sobs died away, and then I said
 * softly to him:--
 *
 * "Come and look at her."
 *
 * Together we moved over to the bed, and I lifted the lawn from her face.
 * God! how beautiful she was. Every hour seemed to be enhancing her
 * loveliness. It frightened and amazed me somewhat; and as for Arthur, he
 * fell a-trembling, and finally was shaken with doubt as with an ague. At
 * last, after a long pause, he said to me in a faint whisper:--
 *
 * "Jack, is she really dead?"
 *
 * I assured him sadly that it was so, and went on to suggest--for I felt
 * that such a horrible doubt should not have life for a moment longer than
 * I could help--that it often happened that after death faces became
 * softened and even resolved into their youthful beauty; that this was
 * especially so when death had been preceded by any acute or prolonged
 * suffering. It seemed to quite do away with any doubt, and, after
 * kneeling beside the couch for a while and looking at her lovingly and
 * long, he turned aside. I told him that that must be good-bye, as the
 * coffin had to be prepared; so he went back and took her dead hand in his
 * and kissed it, and bent over and kissed her forehead. He came away,
 * fondly looking back over his shoulder at her as he came.
 *
 * I left him in the drawing-room, and told Van Helsing that he had said
 * good-bye; so the latter went to the kitchen to tell the undertaker's men
 * to proceed with the preparations and to screw up the coffin. When he
 * came out of the room again I told him of Arthur's question, and he
 * replied:--
 *
 * "I am not surprised. Just now I doubted for a moment myself!"
 *
 * We all dined together, and I could see that poor Art was trying to make
 * the best of things. Van Helsing had been silent all dinner-time; but
 * when we had lit our cigars he said--
 *
 * "Lord----"; but Arthur interrupted him:--
 *
 * "No, no, not that, for God's sake! not yet at any rate. Forgive me, sir:
 * I did not mean to speak offensively; it is only because my loss is so
 * recent."
 *
 * The Professor answered very sweetly:--
 *
 * "I only used that name because I was in doubt. I must not call you
 * 'Mr.,' and I have grown to love you--yes, my dear boy, to love you--as
 * Arthur."
 *
 * Arthur held out his hand, and took the old man's warmly.
 *
 * "Call me what you will," he said. "I hope I may always have the title of
 * a friend. And let me say that I am at a loss for words to thank you for
 * your goodness to my poor dear." He paused a moment, and went on: "I know
 * that she understood your goodness even better than I do; and if I was
 * rude or in any way wanting at that time you acted so--you remember"--the
 * Professor nodded--"you must forgive me."
 *
 * He answered with a grave kindness:--
 *
 * "I know it was hard for you to quite trust me then, for to trust such
 * violence needs to understand; and I take it that you do not--that you
 * cannot--trust me now, for you do not yet understand. And there may be
 * more times when I shall want you to trust when you cannot--and may
 * not--and must not yet understand. But the time will come when your trust
 * shall be whole and complete in me, and when you shall understand as
 * though the sunlight himself shone through. Then you shall bless me from
 * first to last for your own sake, and for the sake of others and for her
 * dear sake to whom I swore to protect."
 *
 * "And, indeed, indeed, sir," said Arthur warmly, "I shall in all ways
 * trust you. I know and believe you have a very noble heart, and you are
 * Jack's friend, and you were hers. You shall do what you like."
 *
 * The Professor cleared his throat a couple of times, as though about to
 * speak, and finally said:--
 *
 * "May I ask you something now?"
 *
 * "Certainly."
 *
 * "You know that Mrs. Westenra left you all her property?"
 *
 * "No, poor dear; I never thought of it."
 *
 * "And as it is all yours, you have a right to deal with it as you will. I
 * want you to give me permission to read all Miss Lucy's papers and
 * letters. Believe me, it is no idle curiosity. I have a motive of which,
 * be sure, she would have approved. I have them all here. I took them
 * before we knew that all was yours, so that no strange hand might touch
 * them--no strange eye look through words into her soul. I shall keep
 * them, if I may; even you may not see them yet, but I shall keep them
 * safe. No word shall be lost; and in the good time I shall give them back
 * to you. It's a hard thing I ask, but you will do it, will you not, for
 * Lucy's sake?"
 *
 * Arthur spoke out heartily, like his old self:--
 *
 * "Dr. Van Helsing, you may do what you will. I feel that in saying this I
 * am doing what my dear one would have approved. I shall not trouble you
 * with questions till the time comes."
 *
 * The old Professor stood up as he said solemnly:--
 *
 * "And you are right. There will be pain for us all; but it will not be
 * all pain, nor will this pain be the last. We and you too--you most of
 * all, my dear boy--will have to pass through the bitter water before we
 * reach the sweet. But we must be brave of heart and unselfish, and do our
 * duty, and all will be well!"
 *
 * I slept on a sofa in Arthur's room that night. Van Helsing did not go to
 * bed at all. He went to and fro, as if patrolling the house, and was
 * never out of sight of the room where Lucy lay in her coffin, strewn with
 * the wild garlic flowers, which sent, through the odour of lily and rose,
 * a heavy, overpowering smell into the night.
 *
 *
 * _Mina Harker's Journal._
 *
 * _22 September._--In the train to Exeter. Jonathan sleeping.
 *
 * It seems only yesterday that the last entry was made, and yet how much
 * between then, in Whitby and all the world before me, Jonathan away and
 * no news of him; and now, married to Jonathan, Jonathan a solicitor, a
 * partner, rich, master of his business, Mr. Hawkins dead and buried, and
 * Jonathan with another attack that may harm him. Some day he may ask me
 * about it. Down it all goes. I am rusty in my shorthand--see what
 * unexpected prosperity does for us--so it may be as well to freshen it up
 * again with an exercise anyhow....
 *
 * The service was very simple and very solemn. There were only ourselves
 * and the servants there, one or two old friends of his from Exeter, his
 * London agent, and a gentleman representing Sir John Paxton, the
 * President of the Incorporated Law Society. Jonathan and I stood hand in
 * hand, and we felt that our best and dearest friend was gone from us....
 *
 * We came back to town quietly, taking a 'bus to Hyde Park Corner.
 * Jonathan thought it would interest me to go into the Row for a while, so
 * we sat down; but there were very few people there, and it was
 * sad-looking and desolate to see so many empty chairs. It made us think
 * of the empty chair at home; so we got up and walked down Piccadilly.
 * Jonathan was holding me by the arm, the way he used to in old days
 * before I went to school. I felt it very improper, for you can't go on
 * for some years teaching etiquette and decorum to other girls without the
 * pedantry of it biting into yourself a bit; but it was Jonathan, and he
 * was my husband, and we didn't know anybody who saw us--and we didn't
 * care if they did--so on we walked. I was looking at a very beautiful
 * girl, in a big cart-wheel hat, sitting in a victoria outside Guiliano's,
 * when I felt Jonathan clutch my arm so tight that he hurt me, and he said
 * under his breath: "My God!" I am always anxious about Jonathan, for I
 * fear that some nervous fit may upset him again; so I turned to him
 * quickly, and asked him what it was that disturbed him.
 *
 * He was very pale, and his eyes seemed bulging out as, half in terror and
 * half in amazement, he gazed at a tall, thin man, with a beaky nose and
 * black moustache and pointed beard, who was also observing the pretty
 * girl. He was looking at her so hard that he did not see either of us,
 * and so I had a good view of him. His face was not a good face; it was
 * hard, and cruel, and sensual, and his big white teeth, that looked all
 * the whiter because his lips were so red, were pointed like an animal's.
 * Jonathan kept staring at him, till I was afraid he would notice. I
 * feared he might take it ill, he looked so fierce and nasty. I asked
 * Jonathan why he was disturbed, and he answered, evidently thinking that
 * I knew as much about it as he did: "Do you see who it is?"
 *
 * "No, dear," I said; "I don't know him; who is it?" His answer seemed to
 * shock and thrill me, for it was said as if he did not know that it was
 * to me, Mina, to whom he was speaking:--
 *
 * "It is the man himself!"
 *
 * The poor dear was evidently terrified at something--very greatly
 * terrified; I do believe that if he had not had me to lean on and to
 * support him he would have sunk down. He kept staring; a man came out of
 * the shop with a small parcel, and gave it to the lady, who then drove
 * off. The dark man kept his eyes fixed on her, and when the carriage
 * moved up Piccadilly he followed in the same direction, and hailed a
 * hansom. Jonathan kept looking after him, and said, as if to himself:--
 *
 * "I believe it is the Count, but he has grown young. My God, if this be
 * so! Oh, my God! my God! If I only knew! if I only knew!" He was
 * distressing himself so much that I feared to keep his mind on the
 * subject by asking him any questions, so I remained silent. I drew him
 * away quietly, and he, holding my arm, came easily. We walked a little
 * further, and then went in and sat for a while in the Green Park. It was
 * a hot day for autumn, and there was a comfortable seat in a shady place.
 * After a few minutes' staring at nothing, Jonathan's eyes closed, and he
 * went quietly into a sleep, with his head on my shoulder. I thought it
 * was the best thing for him, so did not disturb him. In about twenty
 * minutes he woke up, and said to me quite cheerfully:--
 *
 * "Why, Mina, have I been asleep! Oh, do forgive me for being so rude.
 * Come, and we'll have a cup of tea somewhere." He had evidently forgotten
 * all about the dark stranger, as in his illness he had forgotten all that
 * this episode had reminded him of. I don't like this lapsing into
 * forgetfulness; it may make or continue some injury to the brain. I must
 * not ask him, for fear I shall do more harm than good; but I must somehow
 * learn the facts of his journey abroad. The time is come, I fear, when I
 * must open that parcel, and know what is written. Oh, Jonathan, you will,
 * I know, forgive me if I do wrong, but it is for your own dear sake.
 *
 *        *       *       *       *       *
 *
 * _Later._--A sad home-coming in every way--the house empty of the dear
 * soul who was so good to us; Jonathan still pale and dizzy under a slight
 * relapse of his malady; and now a telegram from Van Helsing, whoever he
 * may be:--
 *
 * "You will be grieved to hear that Mrs. Westenra died five days ago, and
 * that Lucy died the day before yesterday. They were both buried to-day."
 *
 * Oh, what a wealth of sorrow in a few words! Poor Mrs. Westenra! poor
 * Lucy! Gone, gone, never to return to us! And poor, poor Arthur, to have
 * lost such sweetness out of his life! God help us all to bear our
 * troubles.
 *
 *
 * _Dr. Seward's Diary._
 *
 * _22 September._--It is all over. Arthur has gone back to Ring, and has
 * taken Quincey Morris with him. What a fine fellow is Quincey! I believe
 * in my heart of hearts that he suffered as much about Lucy's death as any
 * of us; but he bore himself through it like a moral Viking. If America
 * can go on breeding men like that, she will be a power in the world
 * indeed. Van Helsing is lying down, having a rest preparatory to his
 * journey. He goes over to Amsterdam to-night, but says he returns
 * to-morrow night; that he only wants to make some arrangements which can
 * only be made personally. He is to stop with me then, if he can; he says
 * he has work to do in London which may take him some time. Poor old
 * fellow! I fear that the strain of the past week has broken down even his
 * iron strength. All the time of the burial he was, I could see, putting
 * some terrible restraint on himself. When it was all over, we were
 * standing beside Arthur, who, poor fellow, was speaking of his part in
 * the operation where his blood had been transfused to his Lucy's veins; I
 * could see Van Helsing's face grow white and purple by turns. Arthur was
 * saying that he felt since then as if they two had been really married
 * and that she was his wife in the sight of God. None of us said a word of
 * the other operations, and none of us ever shall. Arthur and Quincey went
 * away together to the station, and Van Helsing and I came on here. The
 * moment we were alone in the carriage he gave way to a regular fit of
 * hysterics. He has denied to me since that it was hysterics, and insisted
 * that it was only his sense of humour asserting itself under very
 * terrible conditions. He laughed till he cried, and I had to draw down
 * the blinds lest any one should see us and misjudge; and then he cried,
 * till he laughed again; and laughed and cried together, just as a woman
 * does. I tried to be stern with him, as one is to a woman under the
 * circumstances; but it had no effect. Men and women are so different in
 * manifestations of nervous strength or weakness! Then when his face grew
 * grave and stern again I asked him why his mirth, and why at such a time.
 * His reply was in a way characteristic of him, for it was logical and
 * forceful and mysterious. He said:--
 *
 * "Ah, you don't comprehend, friend John. Do not think that I am not sad,
 * though I laugh. See, I have cried even when the laugh did choke me. But
 * no more think that I am all sorry when I cry, for the laugh he come
 * just the same. Keep it always with you that laughter who knock at your
 * door and say, 'May I come in?' is not the true laughter. No! he is a
 * king, and he come when and how he like. He ask no person; he choose no
 * time of suitability. He say, 'I am here.' Behold, in example I grieve my
 * heart out for that so sweet young girl; I give my blood for her, though
 * I am old and worn; I give my time, my skill, my sleep; I let my other
 * sufferers want that so she may have all. And yet I can laugh at her very
 * grave--laugh when the clay from the spade of the sexton drop upon her
 * coffin and say 'Thud! thud!' to my heart, till it send back the blood
 * from my cheek. My heart bleed for that poor boy--that dear boy, so of
 * the age of mine own boy had I been so blessed that he live, and with his
 * hair and eyes the same. There, you know now why I love him so. And yet
 * when he say things that touch my husband-heart to the quick, and make my
 * father-heart yearn to him as to no other man--not even to you, friend
 * John, for we are more level in experiences than father and son--yet even
 * at such moment King Laugh he come to me and shout and bellow in my ear,
 * 'Here I am! here I am!' till the blood come dance back and bring some of
 * the sunshine that he carry with him to my cheek. Oh, friend John, it is
 * a strange world, a sad world, a world full of miseries, and woes, and
 * troubles; and yet when King Laugh come he make them all dance to the
 * tune he play. Bleeding hearts, and dry bones of the churchyard, and
 * tears that burn as they fall--all dance together to the music that he
 * make with that smileless mouth of him. And believe me, friend John, that
 * he is good to come, and kind. Ah, we men and women are like ropes drawn
 * tight with strain that pull us different ways. Then tears come; and,
 * like the rain on the ropes, they brace us up, until perhaps the strain
 * become too great, and we break. But King Laugh he come like the
 * sunshine, and he ease off the strain again; and we bear to go on with
 * our labour, what it may be."
 *
 * I did not like to wound him by pretending not to see his idea; but, as I
 * did not yet understand the cause of his laughter, I asked him. As he
 * answered me his face grew stern, and he said in quite a different
 * tone:--
 *
 * "Oh, it was the grim irony of it all--this so lovely lady garlanded with
 * flowers, that looked so fair as life, till one by one we wondered if she
 * were truly dead; she laid in that so fine marble house in that lonely
 * churchyard, where rest so many of her kin, laid there with the mother
 * who loved her, and whom she loved; and that sacred bell going 'Toll!
 * toll! toll!' so sad and slow; and those holy men, with the white
 * garments of the angel, pretending to read books, and yet all the time
 * their eyes never on the page; and all of us with the bowed head. And all
 * for what? She is dead; so! Is it not?"
 *
 * "Well, for the life of me, Professor," I said, "I can't see anything to
 * laugh at in all that. Why, your explanation makes it a harder puzzle
 * than before. But even if the burial service was comic, what about poor
 * Art and his trouble? Why, his heart was simply breaking."
 *
 * "Just so. Said he not that the transfusion of his blood to her veins had
 * made her truly his bride?"
 *
 * "Yes, and it was a sweet and comforting idea for him."
 *
 * "Quite so. But there was a difficulty, friend John. If so that, then
 * what about the others? Ho, ho! Then this so sweet maid is a polyandrist,
 * and me, with my poor wife dead to me, but alive by Church's law, though
 * no wits, all gone--even I, who am faithful husband to this now-no-wife,
 * am bigamist."
 *
 * "I don't see where the joke comes in there either!" I said; and I did
 * not feel particularly pleased with him for saying such things. He laid
 * his hand on my arm, and said:--
 *
 * "Friend John, forgive me if I pain. I showed not my feeling to others
 * when it would wound, but only to you, my old friend, whom I can trust.
 * If you could have looked into my very heart then when I want to laugh;
 * if you could have done so when the laugh arrived; if you could do so
 * now, when King Laugh have pack up his crown, and all that is to him--for
 * he go far, far away from me, and for a long, long time--maybe you would
 * perhaps pity me the most of all."
 *
 * I was touched by the tenderness of his tone, and asked why.
 *
 * "Because I know!"
 *
 * And now we are all scattered; and for many a long day loneliness will
 * sit over our roofs with brooding wings. Lucy lies in the tomb of her
 * kin, a lordly death-house in a lonely churchyard, away from teeming
 * London; where the air is fresh, and the sun rises over Hampstead Hill,
 * and where wild flowers grow of their own accord.
 *
 * So I can finish this diary; and God only knows if I shall ever begin
 * another. If I do, or if I even open this again, it will be to deal with
 * different people and different themes; for here at the end, where the
 * romance of my life is told, ere I go back to take up the thread of my
 * life-work, I say sadly and without hope,
 *
 *                         "FINIS."
 *
 *
 * _"The Westminster Gazette," 25 September._
 *
 *                           A HAMPSTEAD MYSTERY.
 *
 *
 * The neighbourhood of Hampstead is just at present exercised with a
 * series of events which seem to run on lines parallel to those of what
 * was known to the writers of headlines as "The Kensington Horror," or
 * "The Stabbing Woman," or "The Woman in Black." During the past two or
 * three days several cases have occurred of young children straying from
 * home or neglecting to return from their playing on the Heath. In all
 * these cases the children were too young to give any properly
 * intelligible account of themselves, but the consensus of their excuses
 * is that they had been with a "bloofer lady." It has always been late in
 * the evening when they have been missed, and on two occasions the
 * children have not been found until early in the following morning. It is
 * generally supposed in the neighbourhood that, as the first child missed
 * gave as his reason for being away that a "bloofer lady" had asked him to
 * come for a walk, the others had picked up the phrase and used it as
 * occasion served. This is the more natural as the favourite game of the
 * little ones at present is luring each other away by wiles. A
 * correspondent writes us that to see some of the tiny tots pretending to
 * be the "bloofer lady" is supremely funny. Some of our caricaturists
 * might, he says, take a lesson in the irony of grotesque by comparing the
 * reality and the picture. It is only in accordance with general
 * principles of human nature that the "bloofer lady" should be the popular
 * rôle at these _al fresco_ performances. Our correspondent naïvely says
 * that even Ellen Terry could not be so winningly attractive as some of
 * these grubby-faced little children pretend--and even imagine
 * themselves--to be.
 *
 * There is, however, possibly a serious side to the question, for some of
 * the children, indeed all who have been missed at night, have been
 * slightly torn or wounded in the throat. The wounds seem such as might be
 * made by a rat or a small dog, and although of not much importance
 * individually, would tend to show that whatever animal inflicts them has
 * a system or method of its own. The police of the division have been
 * instructed to keep a sharp look-out for straying children, especially
 * when very young, in and around Hampstead Heath, and for any stray dog
 * which may be about.
 *
 *
 *                _"The Westminster Gazette," 25 September._
 *
 *                             _Extra Special._
 *
 *                          THE HAMPSTEAD HORROR.
 *
 *                          ANOTHER CHILD INJURED.
 *
 *                          _The "Bloofer Lady."_
 *
 * We have just received intelligence that another child, missed last
 * night, was only discovered late in the morning under a furze bush at the
 * Shooter's Hill side of Hampstead Heath, which is, perhaps, less
 * frequented than the other parts. It has the same tiny wound in the
 * throat as has been noticed in other cases. It was terribly weak, and
 * looked quite emaciated. It too, when partially restored, had the common
 * story to tell of being lured away by the "bloofer lady."
 */
/*                                                                             *
 **                                                                           **
 ***                                                                         ***
 ****                                                                       ****
 *****                                                                     *****
 ******                                                                   ******
 *******                                                                 *******
 ******                                                                   ******
 *****                                                                     *****
 ****                                                                       ****
 ***                                                                         ***
 **                                                                           **
 *                                                                             */
/**
 * \page chapter_XIV CHAPTER XIV: Mina Harker's Journal
 * MINA HARKER'S JOURNAL
 *
 *
 * _23 September_.--Jonathan is better after a bad night. I am so glad that
 * he has plenty of work to do, for that keeps his mind off the terrible
 * things; and oh, I am rejoiced that he is not now weighed down with the
 * responsibility of his new position. I knew he would be true to himself,
 * and now how proud I am to see my Jonathan rising to the height of his
 * advancement and keeping pace in all ways with the duties that come upon
 * him. He will be away all day till late, for he said he could not lunch
 * at home. My household work is done, so I shall take his foreign journal,
 * and lock myself up in my room and read it....
 *
 *
 * _24 September_.--I hadn't the heart to write last night; that terrible
 * record of Jonathan's upset me so. Poor dear! How he must have suffered,
 * whether it be true or only imagination. I wonder if there is any truth
 * in it at all. Did he get his brain fever, and then write all those
 * terrible things, or had he some cause for it all? I suppose I shall
 * never know, for I dare not open the subject to him.... And yet that man
 * we saw yesterday! He seemed quite certain of him.... Poor fellow! I
 * suppose it was the funeral upset him and sent his mind back on some
 * train of thought.... He believes it all himself. I remember how on our
 * wedding-day he said: "Unless some solemn duty come upon me to go back to
 * the bitter hours, asleep or awake, mad or sane." There seems to be
 * through it all some thread of continuity.... That fearful Count was
 * coming to London.... If it should be, and he came to London, with his
 * teeming millions.... There may be a solemn duty; and if it come we must
 * not shrink from it.... I shall be prepared. I shall get my typewriter
 * this very hour and begin transcribing. Then we shall be ready for other
 * eyes if required. And if it be wanted; then, perhaps, if I am ready,
 * poor Jonathan may not be upset, for I can speak for him and never let
 * him be troubled or worried with it at all. If ever Jonathan quite gets
 * over the nervousness he may want to tell me of it all, and I can ask him
 * questions and find out things, and see how I may comfort him.
 *
 *
 * _Letter, Van Helsing to Mrs. Harker._
 *
 * "_24 September._
 *
 * (_Confidence_)
 *
 * "Dear Madam,--
 *
 * "I pray you to pardon my writing, in that I am so far friend as that I
 * sent to you sad news of Miss Lucy Westenra's death. By the kindness of
 * Lord Godalming, I am empowered to read her letters and papers, for I am
 * deeply concerned about certain matters vitally important. In them I find
 * some letters from you, which show how great friends you were and how you
 * love her. Oh, Madam Mina, by that love, I implore you, help me. It is
 * for others' good that I ask--to redress great wrong, and to lift much
 * and terrible troubles--that may be more great than you can know. May it
 * be that I see you? You can trust me. I am friend of Dr. John Seward and
 * of Lord Godalming (that was Arthur of Miss Lucy). I must keep it private
 * for the present from all. I should come to Exeter to see you at once if
 * you tell me I am privilege to come, and where and when. I implore your
 * pardon, madam. I have read your letters to poor Lucy, and know how good
 * you are and how your husband suffer; so I pray you, if it may be,
 * enlighten him not, lest it may harm. Again your pardon, and forgive me.
 *
 * "VAN HELSING."
 *
 *
 * _Telegram, Mrs. Harker to Van Helsing._
 *
 * "_25 September._--Come to-day by quarter-past ten train if you can catch
 * it. Can see you any time you call.
 *
 * "WILHELMINA HARKER."
 *
 * MINA HARKER'S JOURNAL.
 *
 * _25 September._--I cannot help feeling terribly excited as the time
 * draws near for the visit of Dr. Van Helsing, for somehow I expect that
 * it will throw some light upon Jonathan's sad experience; and as he
 * attended poor dear Lucy in her last illness, he can tell me all about
 * her. That is the reason of his coming; it is concerning Lucy and her
 * sleep-walking, and not about Jonathan. Then I shall never know the real
 * truth now! How silly I am. That awful journal gets hold of my
 * imagination and tinges everything with something of its own colour. Of
 * course it is about Lucy. That habit came back to the poor dear, and that
 * awful night on the cliff must have made her ill. I had almost forgotten
 * in my own affairs how ill she was afterwards. She must have told him
 * of her sleep-walking adventure on the cliff, and that I knew all about
 * it; and now he wants me to tell him what she knows, so that he may
 * understand. I hope I did right in not saying anything of it to Mrs.
 * Westenra; I should never forgive myself if any act of mine, were it even
 * a negative one, brought harm on poor dear Lucy. I hope, too, Dr. Van
 * Helsing will not blame me; I have had so much trouble and anxiety of
 * late that I feel I cannot bear more just at present.
 *
 * I suppose a cry does us all good at times--clears the air as other rain
 * does. Perhaps it was reading the journal yesterday that upset me, and
 * then Jonathan went away this morning to stay away from me a whole day
 * and night, the first time we have been parted since our marriage. I do
 * hope the dear fellow will take care of himself, and that nothing will
 * occur to upset him. It is two o'clock, and the doctor will be here soon
 * now. I shall say nothing of Jonathan's journal unless he asks me. I am
 * so glad I have type-written out my own journal, so that, in case he asks
 * about Lucy, I can hand it to him; it will save much questioning.
 *
 *        *       *       *       *       *
 *
 * _Later._--He has come and gone. Oh, what a strange meeting, and how it
 * all makes my head whirl round! I feel like one in a dream. Can it be all
 * possible, or even a part of it? If I had not read Jonathan's journal
 * first, I should never have accepted even a possibility. Poor, poor, dear
 * Jonathan! How he must have suffered. Please the good God, all this may
 * not upset him again. I shall try to save him from it; but it may be even
 * a consolation and a help to him--terrible though it be and awful in its
 * consequences--to know for certain that his eyes and ears and brain did
 * not deceive him, and that it is all true. It may be that it is the doubt
 * which haunts him; that when the doubt is removed, no matter
 * which--waking or dreaming--may prove the truth, he will be more
 * satisfied and better able to bear the shock. Dr. Van Helsing must be a
 * good man as well as a clever one if he is Arthur's friend and Dr.
 * Seward's, and if they brought him all the way from Holland to look after
 * Lucy. I feel from having seen him that he _is_ good and kind and of a
 * noble nature. When he comes to-morrow I shall ask him about Jonathan;
 * and then, please God, all this sorrow and anxiety may lead to a good
 * end. I used to think I would like to practise interviewing; Jonathan's
 * friend on "The Exeter News" told him that memory was everything in such
 * work--that you must be able to put down exactly almost every word
 * spoken, even if you had to refine some of it afterwards. Here was a rare
 * interview; I shall try to record it _verbatim_.
 *
 * It was half-past two o'clock when the knock came. I took my courage _à
 * deux mains_ and waited. In a few minutes Mary opened the door, and
 * announced "Dr. Van Helsing."
 *
 * I rose and bowed, and he came towards me; a man of medium weight,
 * strongly built, with his shoulders set back over a broad, deep chest and
 * a neck well balanced on the trunk as the head is on the neck. The poise
 * of the head strikes one at once as indicative of thought and power; the
 * head is noble, well-sized, broad, and large behind the ears. The face,
 * clean-shaven, shows a hard, square chin, a large, resolute, mobile
 * mouth, a good-sized nose, rather straight, but with quick, sensitive
 * nostrils, that seem to broaden as the big, bushy brows come down and the
 * mouth tightens. The forehead is broad and fine, rising at first almost
 * straight and then sloping back above two bumps or ridges wide apart;
 * such a forehead that the reddish hair cannot possibly tumble over it,
 * but falls naturally back and to the sides. Big, dark blue eyes are set
 * widely apart, and are quick and tender or stern with the man's moods. He
 * said to me:--
 *
 * "Mrs. Harker, is it not?" I bowed assent.
 *
 * "That was Miss Mina Murray?" Again I assented.
 *
 * "It is Mina Murray that I came to see that was friend of that poor dear
 * child Lucy Westenra. Madam Mina, it is on account of the dead I come."
 *
 * "Sir," I said, "you could have no better claim on me than that you were
 * a friend and helper of Lucy Westenra." And I held out my hand. He took
 * it and said tenderly:--
 *
 * "Oh, Madam Mina, I knew that the friend of that poor lily girl must be
 * good, but I had yet to learn----" He finished his speech with a courtly
 * bow. I asked him what it was that he wanted to see me about, so he at
 * once began:--
 *
 * "I have read your letters to Miss Lucy. Forgive me, but I had to begin
 * to inquire somewhere, and there was none to ask. I know that you were
 * with her at Whitby. She sometimes kept a diary--you need not look
 * surprised, Madam Mina; it was begun after you had left, and was in
 * imitation of you--and in that diary she traces by inference certain
 * things to a sleep-walking in which she puts down that you saved her. In
 * great perplexity then I come to you, and ask you out of your so much
 * kindness to tell me all of it that you can remember."
 *
 * "I can tell you, I think, Dr. Van Helsing, all about it."
 *
 * "Ah, then you have good memory for facts, for details? It is not always
 * so with young ladies."
 *
 * "No, doctor, but I wrote it all down at the time. I can show it to you
 * if you like."
 *
 * "Oh, Madam Mina, I will be grateful; you will do me much favour." I
 * could not resist the temptation of mystifying him a bit--I suppose it is
 * some of the taste of the original apple that remains still in our
 * mouths--so I handed him the shorthand diary. He took it with a grateful
 * bow, and said:--
 *
 * "May I read it?"
 *
 * "If you wish," I answered as demurely as I could. He opened it, and for
 * an instant his face fell. Then he stood up and bowed.
 *
 * "Oh, you so clever woman!" he said. "I knew long that Mr. Jonathan was a
 * man of much thankfulness; but see, his wife have all the good things.
 * And will you not so much honour me and so help me as to read it for me?
 * Alas! I know not the shorthand." By this time my little joke was over,
 * and I was almost ashamed; so I took the typewritten copy from my
 * workbasket and handed it to him.
 *
 * "Forgive me," I said: "I could not help it; but I had been thinking that
 * it was of dear Lucy that you wished to ask, and so that you might not
 * have time to wait--not on my account, but because I know your time must
 * be precious--I have written it out on the typewriter for you."
 *
 * He took it and his eyes glistened. "You are so good," he said. "And may
 * I read it now? I may want to ask you some things when I have read."
 *
 * "By all means," I said, "read it over whilst I order lunch; and then you
 * can ask me questions whilst we eat." He bowed and settled himself in a
 * chair with his back to the light, and became absorbed in the papers,
 * whilst I went to see after lunch chiefly in order that he might not be
 * disturbed. When I came back, I found him walking hurriedly up and down
 * the room, his face all ablaze with excitement. He rushed up to me and
 * took me by both hands.
 *
 * "Oh, Madam Mina," he said, "how can I say what I owe to you? This paper
 * is as sunshine. It opens the gate to me. I am daze, I am dazzle, with so
 * much light, and yet clouds roll in behind the light every time. But that
 * you do not, cannot, comprehend. Oh, but I am grateful to you, you so
 * clever woman. Madam"--he said this very solemnly--"if ever Abraham Van
 * Helsing can do anything for you or yours, I trust you will let me know.
 * It will be pleasure and delight if I may serve you as a friend; as a
 * friend, but all I have ever learned, all I can ever do, shall be for you
 * and those you love. There are darknesses in life, and there are lights;
 * you are one of the lights. You will have happy life and good life, and
 * your husband will be blessed in you."
 *
 * "But, doctor, you praise me too much, and--and you do not know me."
 *
 * "Not know you--I, who am old, and who have studied all my life men and
 * women; I, who have made my specialty the brain and all that belongs to
 * him and all that follow from him! And I have read your diary that you
 * have so goodly written for me, and which breathes out truth in every
 * line. I, who have read your so sweet letter to poor Lucy of your
 * marriage and your trust, not know you! Oh, Madam Mina, good women tell
 * all their lives, and by day and by hour and by minute, such things that
 * angels can read; and we men who wish to know have in us something of
 * angels' eyes. Your husband is noble nature, and you are noble too, for
 * you trust, and trust cannot be where there is mean nature. And your
 * husband--tell me of him. Is he quite well? Is all that fever gone, and
 * is he strong and hearty?" I saw here an opening to ask him about
 * Jonathan, so I said:--
 *
 * "He was almost recovered, but he has been greatly upset by Mr. Hawkins's
 * death." He interrupted:--
 *
 * "Oh, yes, I know, I know. I have read your last two letters." I went
 * on:--
 *
 * "I suppose this upset him, for when we were in town on Thursday last he
 * had a sort of shock."
 *
 * "A shock, and after brain fever so soon! That was not good. What kind of
 * a shock was it?"
 *
 * "He thought he saw some one who recalled something terrible, something
 * which led to his brain fever." And here the whole thing seemed to
 * overwhelm me in a rush. The pity for Jonathan, the horror which he
 * experienced, the whole fearful mystery of his diary, and the fear that
 * has been brooding over me ever since, all came in a tumult. I suppose I
 * was hysterical, for I threw myself on my knees and held up my hands to
 * him, and implored him to make my husband well again. He took my hands
 * and raised me up, and made me sit on the sofa, and sat by me; he held my
 * hand in his, and said to me with, oh, such infinite sweetness:--
 *
 * "My life is a barren and lonely one, and so full of work that I have not
 * had much time for friendships; but since I have been summoned to here by
 * my friend John Seward I have known so many good people and seen such
 * nobility that I feel more than ever--and it has grown with my advancing
 * years--the loneliness of my life. Believe, me, then, that I come here
 * full of respect for you, and you have given me hope--hope, not in what I
 * am seeking of, but that there are good women still left to make life
 * happy--good women, whose lives and whose truths may make good lesson for
 * the children that are to be. I am glad, glad, that I may here be of some
 * use to you; for if your husband suffer, he suffer within the range of my
 * study and experience. I promise you that I will gladly do _all_ for him
 * that I can--all to make his life strong and manly, and your life a happy
 * one. Now you must eat. You are overwrought and perhaps over-anxious.
 * Husband Jonathan would not like to see you so pale; and what he like not
 * where he love, is not to his good. Therefore for his sake you must eat
 * and smile. You have told me all about Lucy, and so now we shall not
 * speak of it, lest it distress. I shall stay in Exeter to-night, for I
 * want to think much over what you have told me, and when I have thought I
 * will ask you questions, if I may. And then, too, you will tell me of
 * husband Jonathan's trouble so far as you can, but not yet. You must eat
 * now; afterwards you shall tell me all."
 *
 * After lunch, when we went back to the drawing-room, he said to me:--
 *
 * "And now tell me all about him." When it came to speaking to this great
 * learned man, I began to fear that he would think me a weak fool, and
 * Jonathan a madman--that journal is all so strange--and I hesitated to go
 * on. But he was so sweet and kind, and he had promised to help, and I
 * trusted him, so I said:--
 *
 * "Dr. Van Helsing, what I have to tell you is so queer that you must not
 * laugh at me or at my husband. I have been since yesterday in a sort of
 * fever of doubt; you must be kind to me, and not think me foolish that I
 * have even half believed some very strange things." He reassured me by
 * his manner as well as his words when he said:--
 *
 * "Oh, my dear, if you only know how strange is the matter regarding which
 * I am here, it is you who would laugh. I have learned not to think little
 * of any one's belief, no matter how strange it be. I have tried to keep
 * an open mind; and it is not the ordinary things of life that could close
 * it, but the strange things, the extraordinary things, the things that
 * make one doubt if they be mad or sane."
 *
 * "Thank you, thank you, a thousand times! You have taken a weight off my
 * mind. If you will let me, I shall give you a paper to read. It is long,
 * but I have typewritten it out. It will tell you my trouble and
 * Jonathan's. It is the copy of his journal when abroad, and all that
 * happened. I dare not say anything of it; you will read for yourself and
 * judge. And then when I see you, perhaps, you will be very kind and tell
 * me what you think."
 *
 * "I promise," he said as I gave him the papers; "I shall in the morning,
 * so soon as I can, come to see you and your husband, if I may."
 *
 * "Jonathan will be here at half-past eleven, and you must come to lunch
 * with us and see him then; you could catch the quick 3:34 train, which
 * will leave you at Paddington before eight." He was surprised at my
 * knowledge of the trains off-hand, but he does not know that I have made
 * up all the trains to and from Exeter, so that I may help Jonathan in
 * case he is in a hurry.
 *
 * So he took the papers with him and went away, and I sit here
 * thinking--thinking I don't know what.
 *
 *        *       *       *       *       *
 *
 * _Letter (by hand), Van Helsing to Mrs. Harker._
 *
 * "_25 September, 6 o'clock._
 *
 * "Dear Madam Mina,--
 *
 * "I have read your husband's so wonderful diary. You may sleep without
 * doubt. Strange and terrible as it is, it is _true_! I will pledge my
 * life on it. It may be worse for others; but for him and you there is no
 * dread. He is a noble fellow; and let me tell you from experience of men,
 * that one who would do as he did in going down that wall and to that
 * room--ay, and going a second time--is not one to be injured in
 * permanence by a shock. His brain and his heart are all right; this I
 * swear, before I have even seen him; so be at rest. I shall have much to
 * ask him of other things. I am blessed that to-day I come to see you, for
 * I have learn all at once so much that again I am dazzle--dazzle more
 * than ever, and I must think.
 *
 * "Yours the most faithful,
 *
 * "ABRAHAM VAN HELSING."
 *
 *
 * _Letter, Mrs. Harker to Van Helsing._
 *
 * "_25 September, 6:30 p. m._
 *
 * "My dear Dr. Van Helsing,--
 *
 * "A thousand thanks for your kind letter, which has taken a great weight
 * off my mind. And yet, if it be true, what terrible things there are in
 * the world, and what an awful thing if that man, that monster, be really
 * in London! I fear to think. I have this moment, whilst writing, had a
 * wire from Jonathan, saying that he leaves by the 6:25 to-night from
 * Launceston and will be here at 10:18, so that I shall have no fear
 * to-night. Will you, therefore, instead of lunching with us, please come
 * to breakfast at eight o'clock, if this be not too early for you? You can
 * get away, if you are in a hurry, by the 10:30 train, which will bring
 * you to Paddington by 2:35. Do not answer this, as I shall take it that,
 * if I do not hear, you will come to breakfast.
 *
 * "Believe me,
 *
 * "Your faithful and grateful friend,
 *
 * "MINA HARKER."
 *
 *
 * _Jonathan Harker's Journal._
 *
 * _26 September._--I thought never to write in this diary again, but the
 * time has come. When I got home last night Mina had supper ready, and
 * when we had supped she told me of Van Helsing's visit, and of her having
 * given him the two diaries copied out, and of how anxious she has been
 * about me. She showed me in the doctor's letter that all I wrote down was
 * true. It seems to have made a new man of me. It was the doubt as to the
 * reality of the whole thing that knocked me over. I felt impotent, and in
 * the dark, and distrustful. But, now that I _know_, I am not afraid, even
 * of the Count. He has succeeded after all, then, in his design in getting
 * to London, and it was he I saw. He has got younger, and how? Van Helsing
 * is the man to unmask him and hunt him out, if he is anything like what
 * Mina says. We sat late, and talked it all over. Mina is dressing, and I
 * shall call at the hotel in a few minutes and bring him over....
 *
 * He was, I think, surprised to see me. When I came into the room where he
 * was, and introduced myself, he took me by the shoulder, and turned my
 * face round to the light, and said, after a sharp scrutiny:--
 *
 * "But Madam Mina told me you were ill, that you had had a shock." It was
 * so funny to hear my wife called "Madam Mina" by this kindly,
 * strong-faced old man. I smiled, and said:--
 *
 * "I _was_ ill, I _have_ had a shock; but you have cured me already."
 *
 * "And how?"
 *
 * "By your letter to Mina last night. I was in doubt, and then everything
 * took a hue of unreality, and I did not know what to trust, even the
 * evidence of my own senses. Not knowing what to trust, I did not know
 * what to do; and so had only to keep on working in what had hitherto been
 * the groove of my life. The groove ceased to avail me, and I mistrusted
 * myself. Doctor, you don't know what it is to doubt everything, even
 * yourself. No, you don't; you couldn't with eyebrows like yours." He
 * seemed pleased, and laughed as he said:--
 *
 * "So! You are physiognomist. I learn more here with each hour. I am with
 * so much pleasure coming to you to breakfast; and, oh, sir, you will
 * pardon praise from an old man, but you are blessed in your wife." I
 * would listen to him go on praising Mina for a day, so I simply nodded
 * and stood silent.
 *
 * "She is one of God's women, fashioned by His own hand to show us men and
 * other women that there is a heaven where we can enter, and that its
 * light can be here on earth. So true, so sweet, so noble, so little an
 * egoist--and that, let me tell you, is much in this age, so sceptical and
 * selfish. And you, sir--I have read all the letters to poor Miss Lucy,
 * and some of them speak of you, so I know you since some days from the
 * knowing of others; but I have seen your true self since last night. You
 * will give me your hand, will you not? And let us be friends for all our
 * lives."
 *
 * We shook hands, and he was so earnest and so kind that it made me quite
 * choky.
 *
 * "And now," he said, "may I ask you for some more help? I have a great
 * task to do, and at the beginning it is to know. You can help me here.
 * Can you tell me what went before your going to Transylvania? Later on I
 * may ask more help, and of a different kind; but at first this will do."
 *
 * "Look here, sir," I said, "does what you have to do concern the Count?"
 *
 * "It does," he said solemnly.
 *
 * "Then I am with you heart and soul. As you go by the 10:30 train, you
 * will not have time to read them; but I shall get the bundle of papers.
 * You can take them with you and read them in the train."
 *
 * After breakfast I saw him to the station. When we were parting he
 * said:--
 *
 * "Perhaps you will come to town if I send to you, and take Madam Mina
 * too."
 *
 * "We shall both come when you will," I said.
 *
 * I had got him the morning papers and the London papers of the previous
 * night, and while we were talking at the carriage window, waiting for the
 * train to start, he was turning them over. His eyes suddenly seemed to
 * catch something in one of them, "The Westminster Gazette"--I knew it by
 * the colour--and he grew quite white. He read something intently,
 * groaning to himself: "Mein Gott! Mein Gott! So soon! so soon!" I do not
 * think he remembered me at the moment. Just then the whistle blew, and
 * the train moved off. This recalled him to himself, and he leaned out of
 * the window and waved his hand, calling out: "Love to Madam Mina; I shall
 * write so soon as ever I can."
 *
 *
 * _Dr. Seward's Diary._
 *
 * _26 September._--Truly there is no such thing as finality. Not a week
 * since I said "Finis," and yet here I am starting fresh again, or rather
 * going on with the same record. Until this afternoon I had no cause to
 * think of what is done. Renfield had become, to all intents, as sane as
 * he ever was. He was already well ahead with his fly business; and he had
 * just started in the spider line also; so he had not been of any trouble
 * to me. I had a letter from Arthur, written on Sunday, and from it I
 * gather that he is bearing up wonderfully well. Quincey Morris is with
 * him, and that is much of a help, for he himself is a bubbling well of
 * good spirits. Quincey wrote me a line too, and from him I hear that
 * Arthur is beginning to recover something of his old buoyancy; so as to
 * them all my mind is at rest. As for myself, I was settling down to my
 * work with the enthusiasm which I used to have for it, so that I might
 * fairly have said that the wound which poor Lucy left on me was becoming
 * cicatrised. Everything is, however, now reopened; and what is to be the
 * end God only knows. I have an idea that Van Helsing thinks he knows,
 * too, but he will only let out enough at a time to whet curiosity. He
 * went to Exeter yesterday, and stayed there all night. To-day he came
 * back, and almost bounded into the room at about half-past five o'clock,
 * and thrust last night's "Westminster Gazette" into my hand.
 *
 * "What do you think of that?" he asked as he stood back and folded his
 * arms.
 *
 * I looked over the paper, for I really did not know what he meant; but he
 * took it from me and pointed out a paragraph about children being decoyed
 * away at Hampstead. It did not convey much to me, until I reached a
 * passage where it described small punctured wounds on their throats. An
 * idea struck me, and I looked up. "Well?" he said.
 *
 * "It is like poor Lucy's."
 *
 * "And what do you make of it?"
 *
 * "Simply that there is some cause in common. Whatever it was that injured
 * her has injured them." I did not quite understand his answer:--
 *
 * "That is true indirectly, but not directly."
 *
 * "How do you mean, Professor?" I asked. I was a little inclined to take
 * his seriousness lightly--for, after all, four days of rest and freedom
 * from burning, harrowing anxiety does help to restore one's spirits--but
 * when I saw his face, it sobered me. Never, even in the midst of our
 * despair about poor Lucy, had he looked more stern.
 *
 * "Tell me!" I said. "I can hazard no opinion. I do not know what to
 * think, and I have no data on which to found a conjecture."
 *
 * "Do you mean to tell me, friend John, that you have no suspicion as to
 * what poor Lucy died of; not after all the hints given, not only by
 * events, but by me?"
 *
 * "Of nervous prostration following on great loss or waste of blood."
 *
 * "And how the blood lost or waste?" I shook my head. He stepped over and
 * sat down beside me, and went on:--
 *
 * "You are clever man, friend John; you reason well, and your wit is bold;
 * but you are too prejudiced. You do not let your eyes see nor your ears
 * hear, and that which is outside your daily life is not of account to
 * you. Do you not think that there are things which you cannot understand,
 * and yet which are; that some people see things that others cannot? But
 * there are things old and new which must not be contemplate by men's
 * eyes, because they know--or think they know--some things which other men
 * have told them. Ah, it is the fault of our science that it wants to
 * explain all; and if it explain not, then it says there is nothing to
 * explain. But yet we see around us every day the growth of new beliefs,
 * which think themselves new; and which are yet but the old, which pretend
 * to be young--like the fine ladies at the opera. I suppose now you do not
 * believe in corporeal transference. No? Nor in materialisation. No? Nor
 * in astral bodies. No? Nor in the reading of thought. No? Nor in
 * hypnotism----"
 *
 * "Yes," I said. "Charcot has proved that pretty well." He smiled as he
 * went on: "Then you are satisfied as to it. Yes? And of course then you
 * understand how it act, and can follow the mind of the great
 * Charcot--alas that he is no more!--into the very soul of the patient
 * that he influence. No? Then, friend John, am I to take it that you
 * simply accept fact, and are satisfied to let from premise to conclusion
 * be a blank? No? Then tell me--for I am student of the brain--how you
 * accept the hypnotism and reject the thought reading. Let me tell you, my
 * friend, that there are things done to-day in electrical science which
 * would have been deemed unholy by the very men who discovered
 * electricity--who would themselves not so long before have been burned
 * as wizards. There are always mysteries in life. Why was it that
 * Methuselah lived nine hundred years, and 'Old Parr' one hundred and
 * sixty-nine, and yet that poor Lucy, with four men's blood in her poor
 * veins, could not live even one day? For, had she live one more day, we
 * could have save her. Do you know all the mystery of life and death? Do
 * you know the altogether of comparative anatomy and can say wherefore the
 * qualities of brutes are in some men, and not in others? Can you tell me
 * why, when other spiders die small and soon, that one great spider lived
 * for centuries in the tower of the old Spanish church and grew and grew,
 * till, on descending, he could drink the oil of all the church lamps? Can
 * you tell me why in the Pampas, ay and elsewhere, there are bats that
 * come at night and open the veins of cattle and horses and suck dry their
 * veins; how in some islands of the Western seas there are bats which hang
 * on the trees all day, and those who have seen describe as like giant
 * nuts or pods, and that when the sailors sleep on the deck, because that
 * it is hot, flit down on them, and then--and then in the morning are
 * found dead men, white as even Miss Lucy was?"
 *
 * "Good God, Professor!" I said, starting up. "Do you mean to tell me that
 * Lucy was bitten by such a bat; and that such a thing is here in London
 * in the nineteenth century?" He waved his hand for silence, and went
 * on:--
 *
 * "Can you tell me why the tortoise lives more long than generations of
 * men; why the elephant goes on and on till he have seen dynasties; and
 * why the parrot never die only of bite of cat or dog or other complaint?
 * Can you tell me why men believe in all ages and places that there are
 * some few who live on always if they be permit; that there are men and
 * women who cannot die? We all know--because science has vouched for the
 * fact--that there have been toads shut up in rocks for thousands of
 * years, shut in one so small hole that only hold him since the youth of
 * the world. Can you tell me how the Indian fakir can make himself to die
 * and have been buried, and his grave sealed and corn sowed on it, and the
 * corn reaped and be cut and sown and reaped and cut again, and then men
 * come and take away the unbroken seal and that there lie the Indian
 * fakir, not dead, but that rise up and walk amongst them as before?" Here
 * I interrupted him. I was getting bewildered; he so crowded on my mind
 * his list of nature's eccentricities and possible impossibilities that my
 * imagination was getting fired. I had a dim idea that he was teaching me
 * some lesson, as long ago he used to do in his study at Amsterdam; but
 * he used then to tell me the thing, so that I could have the object of
 * thought in mind all the time. But now I was without this help, yet I
 * wanted to follow him, so I said:--
 *
 * "Professor, let me be your pet student again. Tell me the thesis, so
 * that I may apply your knowledge as you go on. At present I am going in
 * my mind from point to point as a mad man, and not a sane one, follows an
 * idea. I feel like a novice lumbering through a bog in a mist, jumping
 * from one tussock to another in the mere blind effort to move on without
 * knowing where I am going."
 *
 * "That is good image," he said. "Well, I shall tell you. My thesis is
 * this: I want you to believe."
 *
 * "To believe what?"
 *
 * "To believe in things that you cannot. Let me illustrate. I heard once
 * of an American who so defined faith: 'that faculty which enables us to
 * believe things which we know to be untrue.' For one, I follow that man.
 * He meant that we shall have an open mind, and not let a little bit of
 * truth check the rush of a big truth, like a small rock does a railway
 * truck. We get the small truth first. Good! We keep him, and we value
 * him; but all the same we must not let him think himself all the truth in
 * the universe."
 *
 * "Then you want me not to let some previous conviction injure the
 * receptivity of my mind with regard to some strange matter. Do I read
 * your lesson aright?"
 *
 * "Ah, you are my favourite pupil still. It is worth to teach you. Now
 * that you are willing to understand, you have taken the first step to
 * understand. You think then that those so small holes in the children's
 * throats were made by the same that made the hole in Miss Lucy?"
 *
 * "I suppose so." He stood up and said solemnly:--
 *
 * "Then you are wrong. Oh, would it were so! but alas! no. It is worse,
 * far, far worse."
 *
 * "In God's name, Professor Van Helsing, what do you mean?" I cried.
 *
 * He threw himself with a despairing gesture into a chair, and placed his
 * elbows on the table, covering his face with his hands as he spoke:--
 *
 * "They were made by Miss Lucy!"
 */
#endif // DOXYGEN_TEST_PAGES
