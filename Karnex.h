/*
* Karnex.h - <insert interesting description for this header file>
*
* <Insert copyright stuff here>
*
* <Insert GNU stuff here>
*/


#ifndef _KARNEX_H
#define _KARNEX_H


#include Instrument.h
#include InstrumentView.h
#include Oscillator.h
#include Knob.h
//#include (Oscillator Chooser thang, whether it be buttons or whatever)

class Karnex : public Instument
{
  Q_OBJECT//What does this do?
  public:
    Karnex( InstrumentTrack* _instrument_track );//I'm assuming only the skeleton is defined in the .h?
    virtual ~Karnex();//Same.
    
    virtual void playNote(NotePlayHandle* _n, sampleFrame* _working_buffer );
    
    virtual void saveSettings( QDomDocument& _doc, QDomElement& _parent );
    virtual void loadSettings( const QDomElement& _this );
    virtual QString nodeName() const;
    virtual PluginView* instantiateView( QWidget* _parent );
    
  protected slots:
	  void lengthChanged();//Is this just for BitInvader or is it something I would need to include for Karnex?
	  void samplesChanged( int, int );//Ditto.
	
	private:
	  FloatModel  m_sampleLength;
	  graphModel  m_graph;
	
	friend class karnexView;
};//Semicolons are required to terminate class definitions in C++?

class karnexView : public InstrumentView
{
  Q_OBJECT
  public:
    karnexView( Instrument* _instrument, QWidget* _parent );
    virtual ~karnexView();
    
  protected slots:
    void sinWaveClicked();
    void triangleWaveClicked();
    void moogWaveClicked();
    void roundsqrWaveClicked();
    void usrWaveClicked();
    
  private:
    virtual void modelChanged();
    
    knob* m_fmGainKnob;
    knob* m_mouthKnob;
    pixmapButton * m_sinWaveBtn;
    pixmapButton * m_triangleWaveBtn;
    pixmapButton * m_moogWaveBtn;
    pixmapButton * m_roundsqrWaveBtn;
    pixmapButton * m_usrWaveBtn;
    
    static QPixmap* s_artwork;
    
};

#endif
