//=============================================================================================================
/**
* @file     tmsiproducer.h
* @author   Lorenz Esch <lorenz.esch@tu-ilmenau.de>;
*           Christoph Dinh <chdinh@nmr.mgh.harvard.edu>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     February, 2013
*
* @section  LICENSE
*
* Copyright (C) 2013, Lorenz Esch, Christoph Dinh and Matti Hamalainen. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that
* the following conditions are met:
*     * Redistributions of source code must retain the above copyright notice, this list of conditions and the
*       following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
*       the following disclaimer in the documentation and/or other materials provided with the distribution.
*     * Neither the name of the Massachusetts General Hospital nor the names of its contributors may be used
*       to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MASSACHUSETTS GENERAL HOSPITAL BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*
* @brief    Contains the declaration of the TMSIProducer class.
*
*/

#ifndef TMSIPRODUCER_H
#define TMSIPRODUCER_H


//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include <generics/circularbuffer.h>


//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QThread>


//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE TMSIPlugin
//=============================================================================================================

namespace TMSIPlugin
{


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace IOBuffer;


//*************************************************************************************************************
//=============================================================================================================
// FORWARD DECLARATIONS
//=============================================================================================================

class TMSI;


//=============================================================================================================
/**
* DECLARE CLASS ECGProducer
*
* @brief The ECGProducer class provides a ECG data producer for a given sampling rate.
*/
class TMSIProducer : public QThread
{
public:
    typedef QSharedPointer<TMSIProducer> SPtr;              /**< Shared pointer type for ECGProducer. */
    typedef QSharedPointer<const TMSIProducer> ConstSPtr;   /**< Const shared pointer type for ECGProducer. */

    //=========================================================================================================
    /**
    * Constructs a TMSIProducer.
    *
    * @param [in] simulator a pointer to the corresponding ECGSimulator.
    * @param [in] buffer_I a pointer to the buffer to which the ECGProducer should write the generated data for ECG I.
    * @param [in] buffer_II a pointer to the buffer to which the ECGProducer should write the generated data for ECG II.
    * @param [in] buffer_III a pointer to the buffer to which the ECGProducer should write the generated data for ECG III.
    */
    TMSIProducer(TMSI* simulator, dBuffer::SPtr& buffer_I, dBuffer::SPtr& buffer_II, dBuffer::SPtr& buffer_III);

    //=========================================================================================================
    /**
    * Destroys the TMSIProducer.
    */
    ~TMSIProducer();

    //=========================================================================================================
    /**
    * Stops the TMSIProducer by stopping the producer's thread.
    */
    void stop();

protected:
    //=========================================================================================================
    /**
    * The starting point for the thread. After calling start(), the newly created thread calls this function.
    * Returning from this method will end the execution of the thread.
    * Pure virtual method inherited by QThread.
    */
    virtual void run();

private:
    TMSI*                   m_pTMSI;            /**< A pointer to corresponding TMSI.*/
    dBuffer::SPtr           m_pdBuffer_I;       /**< A pointer to the buffer where the simulated data of ECG I should be written to.*/
    dBuffer::SPtr           m_pdBuffer_II;      /**< A pointer to the buffer where the simulated data of ECG II should be written to.*/
    dBuffer::SPtr           m_pdBuffer_III;     /**< A pointer to the buffer where the simulated data of ECG III should be written to.*/
    bool                    m_bIsRunning;       /**< Whether TMSIProducer is running.*/
};

} // NAMESPACE

#endif // TMSIPRODUCER_H
