' MusicString, MusicStringDLL and this VB.NET example are
' Written by Tomas "Frooxius" Mariancik
' http://frooxius.solirax.org/fromVBNET_MSTR
' http://musicstring.solirax.org/fromVBNET_MSTR
' This code and MusicString DLL are to use for non-commercial purposes

Imports System.Runtime.InteropServices

Public Class MusicStringAPI
    <DllImport("MusicStringDLL.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function Init() As Boolean
    End Function
    <DllImport("MusicStringDLL.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Sub SetMusicString(ByVal musstr As String)
    End Sub
    <DllImport("MusicStringDLL.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Sub SetOutFile(ByVal filename As String)
    End Sub
    <DllImport("MusicStringDLL.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Sub SetSampleRate(ByVal rate As UInteger)
    End Sub
    <DllImport("MusicStringDLL.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Sub SetSeconds(ByVal seconds As UInteger)
    End Sub
    <DllImport("MusicStringDLL.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function Play() As Boolean
    End Function
    <DllImport("MusicStringDLL.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Sub Pause()
    End Sub
    <DllImport("MusicStringDLL.dll", CallingConvention:=CallingConvention.Cdecl, EntryPoint:="Stop")> Public Shared Sub StopPlaying()
    End Sub
    <DllImport("MusicStringDLL.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetStatus() As String
    End Function
    <DllImport("MusicStringDLL.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function PhaseCompile() As Integer
    End Function
    <DllImport("MusicStringDLL.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function Compile(ByVal musstr As String, ByVal filename As String, ByVal samplerate As UInteger, ByVal seconds As UInteger) As Boolean
    End Function
End Class
