' MusicString, MusicStringDLL and this VB.NET example are
' Written by Tomas "Frooxius" Mariancik
' http://frooxius.solirax.org/fromVBNET_MSTR
' http://musicstring.solirax.org/fromVBNET_MSTR
' This code and MusicString DLL are to use for non-commercial purposes

Public Class Form1

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        ' It is important to initialize the DLL first, so we can use its methods
        Dim something As Boolean = MusicStringAPI.Init()
    End Sub

    Private Sub buttPlay_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles buttPlay.Click
        ' First, we must load the MusicString code to the DLL
        MusicStringAPI.SetMusicString(textCode.Text)
        ' Now Set the samplerate from the spinbox
        MusicStringAPI.SetSampleRate(spinPlayRate.Value)
        ' Now we call method that will start Playing the MusicString, could it be easier? :3
        MusicStringAPI.Play()
    End Sub

    Private Sub buttPause_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles buttPause.Click
        ' Yaaawn... Do you really want me to explain this?
        MusicStringAPI.Pause()
    End Sub

    Private Sub buttStop_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles buttStop.Click
        ' Seriously, you should feel bad that I made it so simple for you by doing all the complex stuff in C++ x3 Nah, just kidding
        MusicStringAPI.StopPlaying()
    End Sub

    Private Sub buttGen_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles buttGen.Click
        buttGen.Enabled = False ' Disable the button first

        ' Let's get a filename from user first
        Dim result As DialogResult = saveWAV.ShowDialog()
        If Not result = Windows.Forms.DialogResult.OK Then
            ' User didn't confirm the filename, so let's just call the whole thing off
            buttGen.Enabled = True ' Enable it again!
            Return
        End If
        ' Okay, we have a name, let's generate!
        ' First, set the samplerate
        MusicStringAPI.SetSampleRate(spinGenRate.Value)
        ' Now set the time limit (maximum length of generated audio)
        MusicStringAPI.SetSeconds(spinMaxTime.Value)
        ' Set the output file to a temporary file, we move it to user location later
        MusicStringAPI.SetOutFile("temp.wav")
        ' Don't forget to load the MusicString to generate too!
        MusicStringAPI.SetMusicString(textCode.Text)

        ' We're read to generate, we use phase compile, to show messages during compiling!
        Dim compileStatus As Integer
        Do While compileStatus = 0
            compileStatus = MusicStringAPI.PhaseCompile()
            ' Update the message with current status
            labelStatus.Text = MusicStringAPI.GetStatus()
            Update() ' Update the form
        Loop

        ' Check if everything's fine, status 1 means everything went okay
        If compileStatus <> 1 Then
            MessageBox.Show("Sorry folks, something went wrong!")
            buttGen.Enabled = True ' Enable it again!
            Return
        End If

        ' Everything's fine, we can continue and move the generated file to user location
        IO.File.Move("temp.wav", saveWAV.FileName)

        buttGen.Enabled = True ' Enable it again!

        ' We're done! ^^ *bubbles*
    End Sub

    Private Sub LinkLabel1_LinkClicked(ByVal sender As System.Object, ByVal e As System.Windows.Forms.LinkLabelLinkClickedEventArgs) Handles LinkLabel1.LinkClicked
        System.Diagnostics.Process.Start("http://musicstring.solirax.org/fromVBNET_MSTR")
    End Sub

    Private Sub LinkLabel2_LinkClicked(ByVal sender As System.Object, ByVal e As System.Windows.Forms.LinkLabelLinkClickedEventArgs) Handles LinkLabel2.LinkClicked
        System.Diagnostics.Process.Start("http://frooxius.solirax.org/fromVBNET_MSTR")
    End Sub
End Class
