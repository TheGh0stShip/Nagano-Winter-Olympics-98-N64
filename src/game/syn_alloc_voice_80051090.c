/* libultra 2.0I audio/synallocvoice.c, reconstructed from decompals/ultralib. */
#include <os_internal.h>
#include <ultraerror.h>
#include "synthInternals.h"

s32 _allocatePVoice(ALSynth *drvr, PVoice **pvoice, s16 priority);

s32 alSynAllocVoice(ALSynth *drvr, ALVoice *voice, ALVoiceConfig *vc)
{
    PVoice  *pvoice = 0;
    ALFilter *f;
    ALParam *update;
    s32 stolen;

    voice->priority     = vc->priority;
    voice->unityPitch   = vc->unityPitch;
    voice->table        = 0;
    voice->fxBus        = vc->fxBus;
    voice->state        = AL_STOPPED;
    voice->pvoice       = 0;

    stolen = _allocatePVoice(drvr, &pvoice, vc->priority);

    if (pvoice) {
        f = pvoice->channelKnob;

        if (stolen) {
            pvoice->offset = 512;
            pvoice->vvoice->pvoice = 0;

            update = __allocParam();
            update->delta      = drvr->paramSamples;
            update->type       = AL_FILTER_SET_VOLUME;
            update->data.i     = 0;
            update->moredata.i = pvoice->offset - 64;
            (*f->setParam)(f, AL_FILTER_ADD_UPDATE, update);

            update = __allocParam();
            if (update) {
                update->delta  = drvr->paramSamples + pvoice->offset;
                update->type   = AL_FILTER_STOP_VOICE;
                update->next   = 0;
                (*f->setParam)(f, AL_FILTER_ADD_UPDATE, update);
            }
        } else {
            pvoice->offset = 0;
        }

        pvoice->vvoice = voice;
        voice->pvoice  = pvoice;
    }

    return (pvoice != 0);
}

s32 _allocatePVoice(ALSynth *drvr, PVoice **pvoice, s16 priority)
{
    ALLink      *dl;
    PVoice      *pv;
    s32         stolen = 0;

    if ((dl = drvr->pLameList.next) != 0) {
        *pvoice = (PVoice *) dl;
        alUnlink(dl);
        alLink(dl, &drvr->pAllocList);
    } else if ((dl = drvr->pFreeList.next) != 0) {
        *pvoice = (PVoice *) dl;
        alUnlink(dl);
        alLink(dl, &drvr->pAllocList);
    } else {
        for (dl = drvr->pAllocList.next; dl != 0; dl = dl->next) {
            pv = (PVoice *)dl;

            if ((pv->vvoice->priority <= priority) && (pv->offset == 0)) {
                *pvoice = pv;
                priority = pv->vvoice->priority;
                stolen = 1;
            }
        }
    }

    return stolen;
}
