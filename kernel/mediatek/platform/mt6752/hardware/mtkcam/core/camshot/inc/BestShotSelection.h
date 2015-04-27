/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#ifndef _MTK_CAMERA_CORE_CAMSHOT_INC_CAMSHOT_BESTSHOTSELECTION_H_
#define _MTK_CAMERA_CORE_CAMSHOT_INC_CAMSHOT_BESTSHOTSELECTION_H_

#include "MfllCommon.h" //@todo remove this
using namespace std;
using namespace android;
using namespace NSCamNode;

namespace NSCamShot {
////////////////////////////////////////////////////////////////////////////////
struct MF_BSS_PARAM_STRUCT
{
	MUINT8  MF_BSS_ON;
	MUINT32 MF_BSS_ROI_WIDTH;
	MUINT32 MF_BSS_ROI_HEIGHT;
	MUINT32 MF_BSS_ROI_X0;
	MUINT32 MF_BSS_ROI_Y0;
	MUINT32 MF_BSS_SCALE_FACTOR;
	MUINT32 MF_BSS_CLIP_TH0;
	MUINT32 MF_BSS_CLIP_TH1;
	MUINT32 MF_BSS_ZERO;    
};


struct Gmv {
	MINT32	x;
	MINT32	y;
};


struct BSS_INPUT_DATA {
	MUINT32	inMEWidth;
	MUINT32 inMEHeight;
	//
	MUINT8 *Proc1QBImg;
	MUINT8 *Proc1QR1Img;
	MUINT8 *Proc1QR2Img;
	MUINT8 *Proc1QR3Img;
	//
	Gmv gmv[4];
};

struct BSS_OUTPUT_DATA {
	MUINT32	originalOrder[4];
	Gmv gmv[4];
};

class BestShotSelection {
    public:
        //
        static  BestShotSelection*  createInstance();
        virtual MVOID               destroyInstance();
        virtual MBOOL               init(const MF_BSS_PARAM_STRUCT& param) = 0;
        virtual MBOOL               sort(BSS_INPUT_DATA *input, BSS_OUTPUT_DATA *output) = 0;

    protected:
        BestShotSelection();
        virtual ~BestShotSelection();
};

};  // NSCamShot
#endif  //  _MTK_CAMERA_CORE_CAMSHOT_INC_CAMSHOT_BESTSHOTSELECTION_H_


